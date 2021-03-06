#pragma once

#include "qt_opencv_samples/common/OneInputOneOutput.h"
#include <QObject>

namespace qt_opencv_samples {
namespace flip {

using qt_opencv_samples::common::OneInputOneOutput;

class Flip : public OneInputOneOutput
{
    Q_OBJECT
    Q_PROPERTY(int flipCode READ flipCode WRITE setFlipCode NOTIFY flipCodeChanged)

public:
    explicit Flip(QObject* parent = nullptr);
    int flipCode();

signals:
    void flipCodeChanged();

public slots:
    void setFlipCode(int value);

protected:
    void execute(const cv::UMat& source, cv::UMat& dest) override;

private:
    int m_flipCode;
};

} // namespace flip
} // namespace qt_opencv_samples
