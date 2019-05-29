#pragma once

#include "qt_opencv_samples/common/OneInputOneOutput.h"
#include <QObject>

namespace qt_opencv_samples {
namespace rotation {

using qt_opencv_samples::common::OneInputOneOutput;

class Rotation : public OneInputOneOutput
{
    Q_OBJECT
    Q_PROPERTY(double angleInDeg READ angleInDeg WRITE setAngleInDeg NOTIFY angleInDegChanged)

public:
    explicit Rotation(QObject* parent = nullptr);
    double angleInDeg();

signals:
    void angleInDegChanged();

public slots:
    void setAngleInDeg(double value);

protected:
    void execute(const cv::UMat& source, cv::UMat& dest) override;

private:
    double m_angleInDeg;
};

} // namespace rotation
} // namespace qt_opencv_samples
