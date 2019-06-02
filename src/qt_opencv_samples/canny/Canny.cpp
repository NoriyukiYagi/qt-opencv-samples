#include "qt_opencv_samples/canny/Canny.h"

#include <opencv2/opencv.hpp>

namespace qt_opencv_samples {
namespace canny {

Canny::Canny(QObject* parent)
    : OneInputTwoOutput(parent)
    , m_threshold1(40)
    , m_threshold2(200)
{}

void Canny::execute(const cv::UMat& source, cv::UMat& dest1, cv::UMat& dest2)
{
    cv::cvtColor(source, dest1, cv::COLOR_BGR2GRAY);
    cv::Canny(dest1, dest2, threshold1(), threshold2());
}

double Canny::threshold1()
{
    return m_threshold1;
}

void Canny::setThreshold1(double value)
{
    if (!qFuzzyCompare(value, m_threshold1)) {
        m_threshold1 = value;
        emit threshold1Changed();
    }
}

double Canny::threshold2()
{
    return m_threshold2;
}

void Canny::setThreshold2(double value)
{
    if (!qFuzzyCompare(value, m_threshold2)) {
        m_threshold2 = value;
        emit threshold2Changed();
    }
}

} // namespace canny
} // namespace qt_opencv_samples
