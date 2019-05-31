#pragma once

#include "qt_opencv_samples/common/OneInputTwoOutput.h"
#include <QObject>

namespace qt_opencv_samples {
namespace equalize {

using qt_opencv_samples::common::OneInputTwoOutput;

class Equalize : public OneInputTwoOutput
{
    Q_OBJECT

public:
    explicit Equalize(QObject* parent = nullptr);

protected:
    void execute(const cv::UMat& source, cv::UMat& dest1, cv::UMat& dest2) override;
};

} // namespace equalize
} // namespace qt_opencv_samples
