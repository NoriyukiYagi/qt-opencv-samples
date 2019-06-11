#pragma once

#include "qt_opencv_samples/common/OneInputOneOutput.h"
#include <QObject>
#include <QVariantList>

namespace qt_opencv_samples {
namespace detect {

using qt_opencv_samples::common::OneInputOneOutput;

class DetectCorners : public OneInputOneOutput
{
    Q_OBJECT
    Q_PROPERTY(int maxCorners READ maxCorners WRITE setMaxCorners NOTIFY maxCornersChanged)
    Q_PROPERTY(double qualityLevel READ qualityLevel WRITE setQualityLevel NOTIFY qualityLevelChanged)
    Q_PROPERTY(double minDistance READ minDistance WRITE setMinDistance NOTIFY minDistanceChanged)
    Q_PROPERTY(QVariantList detectedCorners READ detectedCorners WRITE setDetectedCorners NOTIFY detectedCornersChanged)

public:
    explicit DetectCorners(QObject* parent = nullptr);
    int maxCorners();
    double qualityLevel();
    double minDistance();
    QVariantList detectedCorners();

signals:
    void maxCornersChanged();
    void qualityLevelChanged();
    void minDistanceChanged();
    void detectedCornersChanged();

public slots:
    void setMaxCorners(int value);
    void setQualityLevel(double value);
    void setMinDistance(double value);
    void setDetectedCorners(QVariantList value);

protected:
    void execute(const cv::UMat& source, cv::UMat& dest) override;

private:
    int m_maxCorners;
    double m_qualityLevel;
    double m_minDistance;
    QVariantList m_detectedCorners;
};

} // namespace detect
} // namespace qt_opencv_samples
