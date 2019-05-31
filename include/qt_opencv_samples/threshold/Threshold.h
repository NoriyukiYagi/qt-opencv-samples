#pragma once

#include "qt_opencv_samples/common/OneInputTwoOutput.h"
#include <QObject>

namespace qt_opencv_samples {
namespace threshold {

using qt_opencv_samples::common::OneInputTwoOutput;

class Threshold : public OneInputTwoOutput
{
    Q_OBJECT
    Q_PROPERTY(double thresh READ thresh WRITE setThresh NOTIFY threshChanged)

public:
    explicit Threshold(QObject* parent = nullptr);
    double thresh();

signals:
    void threshChanged();

public slots:
    void setThresh(double value);

protected:
    void execute(const cv::UMat& source, cv::UMat& dest1, cv::UMat& dest2) override;

private:
    double m_thresh;
};

} // namespace threshold
} // namespace qt_opencv_samples
