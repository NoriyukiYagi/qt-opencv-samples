#include "qt_opencv_samples/flip/Flip.h"

#include <opencv2/opencv.hpp>

namespace qt_opencv_samples {
namespace flip {

Flip::Flip(QObject* parent)
    : QObject(parent)
    , m_flipCode(0)
{}

QUrl Flip::inputFileUrl()
{
    return m_inputFileUrl;
}

void Flip::setInputFileUrl(QUrl value)
{
    if (value != m_inputFileUrl) {
        m_inputFileUrl = value;
        emit inputFileUrlChanged();
    }
}

int Flip::flipCode()
{
    return m_flipCode;
}

void Flip::setFlipCode(int value)
{
    if (value != m_flipCode) {
        m_flipCode = value;
        emit flipCodeChanged();
    }
}

QUrl Flip::outputFileUrl()
{
    return m_outputFileUrl;
}

void Flip::setOutputFileUrl(QUrl value)
{
    if (value != m_outputFileUrl) {
        m_outputFileUrl = value;
        emit outputFileUrlChanged();
    }
}

void Flip::execute()
{
    QUrl inputFile = inputFileUrl();
    if (inputFile.isEmpty()) {
        return;
    }

    cv::Mat source = cv::imread(inputFile.toLocalFile().toStdString());
    cv::Mat dest;
    cv::flip(source, dest, flipCode());

    std::vector<uchar> buf;
    cv::imencode(".png", dest, buf);
    QByteArray byteArray(reinterpret_cast<char*>(buf.data()), static_cast<int>(buf.size()));
    setOutputFileUrl(QUrl("data:image/png;base64," + byteArray.toBase64()));
}

} // namespace flip
} // namespace qt_opencv_samples
