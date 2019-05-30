#pragma once

#include "qt_opencv_samples/common/OneInputOneOutput.h"
#include <QObject>

namespace qt_opencv_samples {
namespace perspective {

using qt_opencv_samples::common::OneInputOneOutput;

class Perspective : public OneInputOneOutput
{
    Q_OBJECT
    Q_PROPERTY(float destLeftTopX READ destLeftTopX WRITE setDestLeftTopX NOTIFY destLeftTopXChanged)
    Q_PROPERTY(float destLeftTopY READ destLeftTopY WRITE setDestLeftTopY NOTIFY destLeftTopYChanged)
    Q_PROPERTY(float destLeftBottomX READ destLeftBottomX WRITE setDestLeftBottomX NOTIFY destLeftBottomXChanged)
    Q_PROPERTY(float destLeftBottomY READ destLeftBottomY WRITE setDestLeftBottomY NOTIFY destLeftBottomYChanged)
    Q_PROPERTY(float destRightTopX READ destRightTopX WRITE setDestRightTopX NOTIFY destRightTopXChanged)
    Q_PROPERTY(float destRightTopY READ destRightTopY WRITE setDestRightTopY NOTIFY destRightTopYChanged)
    Q_PROPERTY(float destRightBottomX READ destRightBottomX WRITE setDestRightBottomX NOTIFY destRightBottomXChanged)
    Q_PROPERTY(float destRightBottomY READ destRightBottomY WRITE setDestRightBottomY NOTIFY destRightBottomYChanged)

public:
    explicit Perspective(QObject* parent = nullptr);
    float destLeftTopX();
    float destLeftTopY();
    float destRightTopX();
    float destRightTopY();
    float destLeftBottomX();
    float destLeftBottomY();
    float destRightBottomX();
    float destRightBottomY();

signals:
    void destLeftTopXChanged();
    void destLeftTopYChanged();
    void destRightTopXChanged();
    void destRightTopYChanged();
    void destLeftBottomXChanged();
    void destLeftBottomYChanged();
    void destRightBottomXChanged();
    void destRightBottomYChanged();

public slots:
    void setDestLeftTopX(float value);
    void setDestLeftTopY(float value);
    void setDestRightTopX(float value);
    void setDestRightTopY(float value);
    void setDestLeftBottomX(float value);
    void setDestLeftBottomY(float value);
    void setDestRightBottomX(float value);
    void setDestRightBottomY(float value);

protected:
    void execute(const cv::UMat& source, cv::UMat& dest) override;

private:
    float m_destLeftTopX;
    float m_destLeftTopY;
    float m_destRightTopX;
    float m_destRightTopY;
    float m_destLeftBottomX;
    float m_destLeftBottomY;
    float m_destRightBottomX;
    float m_destRightBottomY;
};

} // namespace perspective
} // namespace qt_opencv_samples
