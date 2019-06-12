#pragma once

#include "qt_opencv_samples/common/OneInputOneOutput.h"
#include <QObject>
#include <QTemporaryFile>
#include <QVariantList>

namespace qt_opencv_samples {
namespace detect {

using qt_opencv_samples::common::OneInputOneOutput;

class DetectObjects : public OneInputOneOutput
{
    Q_OBJECT
    Q_PROPERTY(QUrl cascadeFileUrl READ cascadeFileUrl WRITE setCascadeFileUrl NOTIFY cascadeFileUrlChanged)
    Q_PROPERTY(QVariantList detectedObjects READ detectedObjects WRITE setDetectedObjects NOTIFY detectedObjectsChanged)
    Q_PROPERTY(QVariantList cascadeFileUrls READ cascadeFileUrls NOTIFY cascadeFileUrlsChanged)

public:
    explicit DetectObjects(QObject* parent = nullptr);
    QUrl cascadeFileUrl();
    QVariantList cascadeFileUrls();
    QVariantList detectedObjects();

signals:
    void cascadeFileUrlChanged();
    void cascadeFileUrlsChanged();
    void detectedObjectsChanged();

public slots:
    void setCascadeFileUrl(QUrl value);
    void setDetectedObjects(QVariantList value);

protected:
    void execute(const cv::UMat& source, cv::UMat& dest) override;

private:
    QUrl m_cascadeFileUrl;
    QVariantList m_cascadeFileUrls;
    cv::CascadeClassifier m_cascadeClassfier;
    QVariantList m_detectedObjects;
};

} // namespace detect
} // namespace qt_opencv_samples
