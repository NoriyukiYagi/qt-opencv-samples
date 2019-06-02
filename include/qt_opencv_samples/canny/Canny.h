#pragma once

#include "qt_opencv_samples/common/OneInputTwoOutput.h"
#include <QObject>

namespace qt_opencv_samples {
namespace canny {

using qt_opencv_samples::common::OneInputTwoOutput;

class Canny : public OneInputTwoOutput
{
    Q_OBJECT
    Q_PROPERTY(double threshold1 READ threshold1 WRITE setThreshold1 NOTIFY threshold1Changed)
    Q_PROPERTY(double threshold2 READ threshold2 WRITE setThreshold2 NOTIFY threshold2Changed)

public:
    explicit Canny(QObject* parent = nullptr);
    double threshold1();
    double threshold2();

signals:
    void threshold1Changed();
    void threshold2Changed();

public slots:
    void setThreshold1(double value);
    void setThreshold2(double value);

protected:
    void execute(const cv::UMat& source, cv::UMat& dest1, cv::UMat& dest2) override;

private:
    double m_threshold1;
    double m_threshold2;
};

} // namespace canny
} // namespace qt_opencv_samples
