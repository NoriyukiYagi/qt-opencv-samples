#pragma once

#include <opencv2/opencv.hpp>
#include <QObject>
#include <QUrl>

namespace qt_opencv_samples {
namespace common {

class OneInputOneOutput : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QUrl inputFileUrl READ inputFileUrl WRITE setInputFileUrl NOTIFY inputFileUrlChanged)
    Q_PROPERTY(QUrl outputFileUrl READ outputFileUrl WRITE setOutputFileUrl NOTIFY outputFileUrlChanged)

public:
    explicit OneInputOneOutput(QObject* parent = nullptr);
    QUrl inputFileUrl();
    QUrl outputFileUrl();
    Q_INVOKABLE void execute();

signals:
    void inputFileUrlChanged();
    void outputFileUrlChanged();

public slots:
    void setInputFileUrl(QUrl value);
    void setOutputFileUrl(QUrl value);

protected:
    virtual void execute(const cv::UMat& source, cv::UMat& dest) = 0;

private:
    QUrl m_inputFileUrl;
    QUrl m_outputFileUrl;
};

} // namespace common
} // namespace qt_opencv_samples
