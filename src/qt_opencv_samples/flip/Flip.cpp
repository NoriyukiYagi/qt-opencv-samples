#include "qt_opencv_samples/flip/Flip.h"

#include <opencv2/opencv.hpp>

namespace qt_opencv_samples {
namespace flip {

Flip::Flip(QObject* parent)
    : OneInputOneOutput(parent)
    , m_flipCode(0)
{}

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

void Flip::execute(const cv::UMat& source, cv::UMat& dest)
{
    cv::flip(source, dest, flipCode());
}

} // namespace flip
} // namespace qt_opencv_samples
