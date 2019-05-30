#include "qt_opencv_samples/common/OneInputOneOutput.h"

#include <QDataStream>
#include <QDebug>
#include <QFile>
#include <QFileInfo>

namespace qt_opencv_samples {
namespace common {

OneInputOneOutput::OneInputOneOutput(QObject* parent)
    : QObject(parent)
    , m_inputFileUrl("qrc:/img/lena_std.png")
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

    QString inputFilePath;
    if (inputFile.isLocalFile()) {
        inputFilePath = inputFile.toLocalFile();
    } else {
        inputFilePath = inputFile.toString();
        if (inputFilePath.startsWith("qrc:")) {
            inputFilePath = inputFilePath.right(inputFilePath.size() - 3); // remove 'qrc'
        }
    }

    QFile f(inputFilePath);
    f.open(QIODevice::ReadOnly);
    QByteArray data = f.readAll();
    f.close();

    cv::UMat source;
    cv::Mat loaded = cv::imdecode(std::vector<uchar>(data.begin(), data.end()), 1);
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
