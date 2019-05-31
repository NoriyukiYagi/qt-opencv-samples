#include "qt_opencv_samples/common/OneInputTwoOutput.h"

#include <QDataStream>
#include <QDebug>
#include <QFile>
#include <QFileInfo>

namespace qt_opencv_samples {
namespace common {

OneInputTwoOutput::OneInputTwoOutput(QObject* parent)
    : QObject(parent)
    , m_inputFileUrl("qrc:/img/lena_std.png")
{}

QUrl OneInputTwoOutput::inputFileUrl()
{
    return m_inputFileUrl;
}

void OneInputTwoOutput::setInputFileUrl(QUrl value)
{
    if (value != m_inputFileUrl) {
        m_inputFileUrl = value;
        emit inputFileUrlChanged();
    }
}

QUrl OneInputTwoOutput::output1FileUrl()
{
    return m_output1FileUrl;
}

void OneInputTwoOutput::setOutput1FileUrl(QUrl value)
{
    if (value != m_output1FileUrl) {
        m_output1FileUrl = value;
        emit output1FileUrlChanged();
    }
}

QUrl OneInputTwoOutput::output2FileUrl()
{
    return m_output2FileUrl;
}

void OneInputTwoOutput::setOutput2FileUrl(QUrl value)
{
    if (value != m_output2FileUrl) {
        m_output2FileUrl = value;
        emit output2FileUrlChanged();
    }
}

void OneInputTwoOutput::execute()
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
    cv::UMat dest1;
    cv::UMat dest2;

    execute(source, dest1, dest2);

    std::vector<uchar> buf1;
    cv::imencode(".png", dest1, buf1);
    QByteArray byteArray1(reinterpret_cast<char*>(buf1.data()), static_cast<int>(buf1.size()));
    setOutput1FileUrl(QUrl("data:image/png;base64," + byteArray1.toBase64()));

    std::vector<uchar> buf2;
    cv::imencode(".png", dest2, buf2);
    QByteArray byteArray2(reinterpret_cast<char*>(buf2.data()), static_cast<int>(buf2.size()));
    setOutput2FileUrl(QUrl("data:image/png;base64," + byteArray2.toBase64()));
}

} // namespace common
} // namespace qt_opencv_samples
