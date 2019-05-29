#include "qt_opencv_samples/common/OneInputOneOutput.h"

namespace qt_opencv_samples {
namespace common {

OneInputOneOutput::OneInputOneOutput(QObject* parent)
    : QObject(parent)
{}

QUrl OneInputOneOutput::inputFileUrl()
{
    return m_inputFileUrl;
}

void OneInputOneOutput::setInputFileUrl(QUrl value)
{
    if (value != m_inputFileUrl) {
        m_inputFileUrl = value;
        emit inputFileUrlChanged();
    }
}

QUrl OneInputOneOutput::outputFileUrl()
{
    return m_outputFileUrl;
}

void OneInputOneOutput::setOutputFileUrl(QUrl value)
{
    if (value != m_outputFileUrl) {
        m_outputFileUrl = value;
        emit outputFileUrlChanged();
    }
}

void OneInputOneOutput::execute()
{
    QUrl inputFile = inputFileUrl();
    if (inputFile.isEmpty()) {
        return;
    }

    cv::UMat source;
    cv::Mat loaded = cv::imread(inputFile.toLocalFile().toStdString());
    loaded.copyTo(source);
    cv::UMat dest;

    execute(source, dest);

    std::vector<uchar> buf;
    cv::imencode(".png", dest, buf);
    QByteArray byteArray(reinterpret_cast<char*>(buf.data()), static_cast<int>(buf.size()));
    setOutputFileUrl(QUrl("data:image/png;base64," + byteArray.toBase64()));
}

} // namespace common
} // namespace qt_opencv_samples
