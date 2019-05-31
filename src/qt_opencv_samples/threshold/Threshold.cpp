#include "qt_opencv_samples/threshold/Threshold.h"

#include <opencv2/opencv.hpp>

namespace qt_opencv_samples {
namespace threshold {

Threshold::Threshold(QObject* parent)
    : OneInputTwoOutput(parent)
    , m_thresh(128)
{}

void Threshold::execute(const cv::UMat& source, cv::UMat& dest1, cv::UMat& dest2)
{
    cv::cvtColor(source, dest1, cv::COLOR_BGR2GRAY);
    cv::threshold(dest1, dest2, thresh(), 255, cv::THRESH_BINARY);
}

double Threshold::thresh()
{
    return m_thresh;
}

void Threshold::setThresh(double value)
{
    if (!qFuzzyCompare(value, m_thresh)) {
        m_thresh = value;
        emit threshChanged();
    }
}

} // namespace threshold
} // namespace qt_opencv_samples
