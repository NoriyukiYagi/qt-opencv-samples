#pragma once

#include "qt_opencv_samples/common/OneInputOneOutput.h"
#include <QObject>

namespace qt_opencv_samples {
namespace canny {

using qt_opencv_samples::common::OneInputOneOutput;

class Canny : public OneInputOneOutput
{
    Q_OBJECT
    Q_PROPERTY(double threshold1 READ threshold1 WRITE setThreshold1 NOTIFY threshold1Changed)
    Q_PROPERTY(double threshold2 READ threshold2 WRITE setThreshold2 NOTIFY threshold2Changed)
    Q_PROPERTY(bool equalize READ equalize WRITE setEqualize NOTIFY equalizeChanged)

public:
    explicit Canny(QObject* parent = nullptr);
    double threshold1();
    double threshold2();
    bool equalize();

signals:
    void threshold1Changed();
    void threshold2Changed();
    void equalizeChanged();

public slots:
    void setThreshold1(double value);
    void setThreshold2(double value);
    void setEqualize(bool value);

protected:
    void execute(const cv::UMat& source, cv::UMat& dest) override;

private:
    double m_threshold1;
    double m_threshold2;
    bool m_equalize;
};

} // namespace canny
} // namespace qt_opencv_samples
