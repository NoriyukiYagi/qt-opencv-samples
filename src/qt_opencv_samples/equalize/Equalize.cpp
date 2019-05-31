#include "qt_opencv_samples/equalize/Equalize.h"

#include <opencv2/opencv.hpp>

namespace qt_opencv_samples {
namespace equalize {

Equalize::Equalize(QObject* parent)
    : OneInputTwoOutput(parent)
{}

void Equalize::execute(const cv::UMat& source, cv::UMat& dest1, cv::UMat& dest2)
{
    cv::cvtColor(source, dest1, cv::COLOR_BGR2GRAY);
    cv::equalizeHist(dest1, dest2);
}

} // namespace equalize
} // namespace qt_opencv_samples
