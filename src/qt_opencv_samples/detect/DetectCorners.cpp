#include "qt_opencv_samples/detect/DetectCorners.h"

#include <opencv2/opencv.hpp>
#include <QPointF>

namespace qt_opencv_samples {
namespace detect {

DetectCorners::DetectCorners(QObject* parent)
    : OneInputOneOutput(parent)
    , m_maxCorners(50)
    , m_qualityLevel(0.01)
    , m_minDistance(20)
{}

void DetectCorners::execute(const cv::UMat& source, cv::UMat& dest)
{
    cv::cvtColor(source, dest, cv::COLOR_BGR2GRAY);

    std::vector<cv::Point2f> corners;
    cv::goodFeaturesToTrack(dest, corners, maxCorners(), qualityLevel(), minDistance());

    QVariantList newDetectedCorners;
    for (const auto& p : corners) {
        newDetectedCorners.push_back(QVariant::fromValue(QPointF(p.x, p.y)));
    }
    setDetectedCorners(newDetectedCorners);
}

int DetectCorners::maxCorners()
{
    return m_maxCorners;
}

double DetectCorners::qualityLevel()
{
    return m_qualityLevel;
}

double DetectCorners::minDistance()
{
    return m_minDistance;
}

QVariantList DetectCorners::detectedCorners()
{
    return m_detectedCorners;
}

void DetectCorners::setMaxCorners(int value)
{
    if (value != m_maxCorners) {
        m_maxCorners = value;
        emit maxCornersChanged();
    }
}

void DetectCorners::setQualityLevel(double value)
{
    if (!qFuzzyCompare(value, m_qualityLevel)) {
        m_qualityLevel = value;
        emit qualityLevelChanged();
    }
}

void DetectCorners::setMinDistance(double value)
{
    if (!qFuzzyCompare(value, m_minDistance)) {
        m_minDistance = value;
        emit minDistanceChanged();
    }
}

void DetectCorners::setDetectedCorners(QVariantList value)
{
    if (value != m_detectedCorners) {
        m_detectedCorners = value;
        emit detectedCornersChanged();
    }
}

} // namespace detect
} // namespace qt_opencv_samples
