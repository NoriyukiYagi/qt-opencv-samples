#include "qt_opencv_samples/perspective/Perspective.h"

#include <QtGlobal>

namespace qt_opencv_samples {
namespace perspective {

Perspective::Perspective(QObject* parent)
    : OneInputOneOutput(parent)
{}

float Perspective::destLeftTopX()
{
    return m_destLeftTopX;
}

void Perspective::setDestLeftTopX(float value)
{
    if (!qFuzzyCompare(value, m_destLeftTopX)) {
        m_destLeftTopX = value;
        emit destLeftTopXChanged();
    }
}

float Perspective::destLeftTopY()
{
    return m_destLeftTopY;
}

void Perspective::setDestLeftTopY(float value)
{
    if (!qFuzzyCompare(value, m_destLeftTopY)) {
        m_destLeftTopY = value;
        emit destLeftTopYChanged();
    }
}

float Perspective::destLeftBottomX()
{
    return m_destLeftBottomX;
}

void Perspective::setDestLeftBottomX(float value)
{
    if (!qFuzzyCompare(value, m_destLeftBottomX)) {
        m_destLeftBottomX = value;
        emit destLeftBottomXChanged();
    }
}

float Perspective::destLeftBottomY()
{
    return m_destLeftBottomY;
}

void Perspective::setDestLeftBottomY(float value)
{
    if (!qFuzzyCompare(value, m_destLeftBottomY)) {
        m_destLeftBottomY = value;
        emit destLeftBottomYChanged();
    }
}

float Perspective::destRightTopX()
{
    return m_destRightTopX;
}

void Perspective::setDestRightTopX(float value)
{
    if (!qFuzzyCompare(value, m_destRightTopX)) {
        m_destRightTopX = value;
        emit destRightTopXChanged();
    }
}

float Perspective::destRightTopY()
{
    return m_destRightTopY;
}

void Perspective::setDestRightTopY(float value)
{
    if (!qFuzzyCompare(value, m_destRightTopY)) {
        m_destRightTopY = value;
        emit destRightTopYChanged();
    }
}

float Perspective::destRightBottomX()
{
    return m_destRightBottomX;
}

void Perspective::setDestRightBottomX(float value)
{
    if (!qFuzzyCompare(value, m_destRightBottomX)) {
        m_destRightBottomX = value;
        emit destRightBottomXChanged();
    }
}

float Perspective::destRightBottomY()
{
    return m_destRightBottomY;
}

void Perspective::setDestRightBottomY(float value)
{
    if (!qFuzzyCompare(value, m_destRightBottomY)) {
        m_destRightBottomY = value;
        emit destRightBottomYChanged();
    }
}

void Perspective::execute(const cv::UMat& source, cv::UMat& dest)
{
    int width = source.cols;
    int height = source.rows;
    cv::Point2f srcPoints[] = {cv::Point2f(0, 0),
                               cv::Point2f(0, width),
                               cv::Point2f(width, height),
                               cv::Point2f(width, 0)};
    cv::Point2f dstPoints[] = {cv::Point2f(destLeftTopX(), destLeftTopY()),
                               cv::Point2f(destLeftBottomX(), destLeftBottomY()),
                               cv::Point2f(destRightBottomX(), destRightBottomY()),
                               cv::Point2f(destRightTopX(), destRightTopY())};
    cv::Mat mat = cv::getPerspectiveTransform(srcPoints, dstPoints);
    cv::warpPerspective(source, dest, mat, source.size());
};

} // namespace perspective
} // namespace qt_opencv_samples
