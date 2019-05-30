#include "qt_opencv_samples/rotation/Rotation.h"

#include <opencv2/opencv.hpp>
#include <QtGlobal>

namespace qt_opencv_samples {
namespace rotation {

Rotation::Rotation(QObject* parent)
    : OneInputOneOutput(parent)
    , m_angleInDeg(0)
{}

double Rotation::angleInDeg()
{
    return m_angleInDeg;
}

void Rotation::setAngleInDeg(double value)
{
    if (!qFuzzyCompare(value, m_angleInDeg)) {
        m_angleInDeg = value;
        emit angleInDegChanged();
    }
}

void Rotation::execute(const cv::UMat& source, cv::UMat& dest)
{
    cv::Point2f center(source.cols / 2, source.rows / 2);
    cv::Mat affineTrans = cv::getRotationMatrix2D(center, angleInDeg(), 1.0);
    cv::warpAffine(source, dest, affineTrans, source.size());
}

} // namespace rotation
} // namespace qt_opencv_samples
