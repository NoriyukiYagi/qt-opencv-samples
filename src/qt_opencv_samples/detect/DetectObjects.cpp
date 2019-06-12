#include "qt_opencv_samples/detect/DetectObjects.h"

#include <opencv2/opencv.hpp>
#include <QDebug>
#include <QDirIterator>
#include <QRect>

namespace qt_opencv_samples {
namespace detect {

DetectObjects::DetectObjects(QObject* parent)
    : OneInputOneOutput(parent)
{
    QDirIterator dataDirIterator(":/data", QDirIterator::IteratorFlag::Subdirectories);
    while (dataDirIterator.hasNext()) {
        QString path = dataDirIterator.next();
        QFileInfo fileInfo(path);
        if (fileInfo.isFile()) {
            m_cascadeFileUrls.append(QVariant::fromValue(QUrl("qrc" + path)));
        }
    }

    setCascadeFileUrl(m_cascadeFileUrls.first().toUrl());
}

void DetectObjects::execute(const cv::UMat& source, cv::UMat& dest)
{
    cv::cvtColor(source, dest, cv::COLOR_BGR2GRAY);

    std::vector<cv::Rect> detectedObjects;
    m_cascadeClassfier.detectMultiScale(source, detectedObjects);

    QVariantList newDetectedObjects;
    for (const auto& r : detectedObjects) {
        newDetectedObjects.push_back(QVariant::fromValue(QRect(r.x, r.y, r.width, r.height)));
    }
    setDetectedObjects(newDetectedObjects);
}

QUrl DetectObjects::cascadeFileUrl()
{
    return m_cascadeFileUrl;
}

QVariantList DetectObjects::cascadeFileUrls()
{
    return m_cascadeFileUrls;
}

QVariantList DetectObjects::detectedObjects()
{
    return m_detectedObjects;
}

void DetectObjects::setCascadeFileUrl(QUrl value)
{
    if (value != m_cascadeFileUrl) {
        m_cascadeFileUrl = value;

        QString cascadeFilePath;
        if (m_cascadeFileUrl.isLocalFile()) {
            cascadeFilePath = m_cascadeFileUrl.toLocalFile();
        } else {
            cascadeFilePath = m_cascadeFileUrl.toString();
            if (cascadeFilePath.startsWith("qrc:")) {
                cascadeFilePath = cascadeFilePath.right(cascadeFilePath.size() - 3); // remove 'qrc'
            }
        }
        QFileInfo cascadeFileInfo(cascadeFilePath);
        QTemporaryFile f(cascadeFileInfo.fileName());
        QFile::copy(cascadeFilePath, f.fileTemplate());
        m_cascadeClassfier.load(f.fileTemplate().toStdString());

        emit cascadeFileUrlChanged();
    }
}

void DetectObjects::setDetectedObjects(QVariantList value)
{
    if (value != m_detectedObjects) {
        m_detectedObjects = value;
        emit detectedObjectsChanged();
    }
}

} // namespace detect
} // namespace qt_opencv_samples
