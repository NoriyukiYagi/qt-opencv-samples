#include "qt_opencv_samples/blur/Blur.h"

#include <opencv2/opencv.hpp>

namespace qt_opencv_samples {
namespace blur {

Blur::Blur(QObject* parent)
    : OneInputOneOutput(parent)
    , m_kernelSize(1)
{}

int Blur::kernelSize()
{
    return m_kernelSize;
}

void Blur::setKernelSize(int value)
{
    if (value != m_kernelSize) {
        m_kernelSize = value;
        emit kernelSizeChanged();
    }
}

void Blur::execute(const cv::UMat& source, cv::UMat& dest)
{
    int k = kernelSize();
    cv::blur(source, dest, cv::Size(k, k));
}

} // namespace blur
} // namespace qt_opencv_samples
