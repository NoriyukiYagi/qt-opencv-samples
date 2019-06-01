#pragma once

#include "qt_opencv_samples/common/OneInputOneOutput.h"
#include <QObject>

namespace qt_opencv_samples {
namespace blur {

using qt_opencv_samples::common::OneInputOneOutput;

class Blur : public OneInputOneOutput
{
    Q_OBJECT
    Q_PROPERTY(int kernelSize READ kernelSize WRITE setKernelSize NOTIFY kernelSizeChanged)

public:
    explicit Blur(QObject* parent = nullptr);
    int kernelSize();

signals:
    void kernelSizeChanged();

public slots:
    void setKernelSize(int value);

protected:
    void execute(const cv::UMat& source, cv::UMat& dest) override;

private:
    int m_kernelSize;
};

} // namespace blur
} // namespace qt_opencv_samples
