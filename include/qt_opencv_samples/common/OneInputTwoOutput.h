#pragma once

#include <opencv2/opencv.hpp>
#include <QObject>
#include <QUrl>

namespace qt_opencv_samples {
namespace common {

class OneInputTwoOutput : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QUrl inputFileUrl READ inputFileUrl WRITE setInputFileUrl NOTIFY inputFileUrlChanged)
    Q_PROPERTY(QUrl output1FileUrl READ output1FileUrl WRITE setOutput1FileUrl NOTIFY output1FileUrlChanged)
    Q_PROPERTY(QUrl output2FileUrl READ output2FileUrl WRITE setOutput2FileUrl NOTIFY output2FileUrlChanged)

public:
    explicit OneInputTwoOutput(QObject* parent = nullptr);
    QUrl inputFileUrl();
    QUrl output1FileUrl();
    QUrl output2FileUrl();
    Q_INVOKABLE void execute();

signals:
    void inputFileUrlChanged();
    void output1FileUrlChanged();
    void output2FileUrlChanged();

public slots:
    void setInputFileUrl(QUrl value);
    void setOutput1FileUrl(QUrl value);
    void setOutput2FileUrl(QUrl value);

protected:
    virtual void execute(const cv::UMat& source, cv::UMat& dest1, cv::UMat& dest2) = 0;

private:
    QUrl m_inputFileUrl;
    QUrl m_output1FileUrl;
    QUrl m_output2FileUrl;
};

} // namespace common
} // namespace qt_opencv_samples
