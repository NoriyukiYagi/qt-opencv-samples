#include "qt_opencv_samples/canny/Canny.h"

#include <opencv2/opencv.hpp>

namespace qt_opencv_samples {
namespace canny {

Canny::Canny(QObject* parent)
    : OneInputOneOutput(parent)
    , m_threshold1(60)
    , m_threshold2(180)
    , m_equalize(false)
{}

void Canny::execute(const cv::UMat& source, cv::UMat& dest)
{
    cv::UMat gray;
    cv::cvtColor(source, gray, cv::COLOR_BGR2GRAY);

    cv::UMat equalizedOrNot;
    if (equalize()) {
        cv::equalizeHist(gray, equalizedOrNot);
    } else {
        equalizedOrNot = gray;
    }

    cv::Canny(equalizedOrNot, dest, threshold1(), threshold2());
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

bool Canny::equalize() {
    return m_equalize;
}

void Canny::setEqualize(bool value) {
    if (value != m_equalize) {
        m_equalize = value;
        emit equalizeChanged();
    }
}

} // namespace canny
} // namespace qt_opencv_samples
