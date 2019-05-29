#pragma once

#include <QObject>
#include <QUrl>

namespace qt_opencv_samples {
namespace flip {

class Flip : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QUrl inputFileUrl READ inputFileUrl WRITE setInputFileUrl NOTIFY inputFileUrlChanged)
    Q_PROPERTY(int flipCode READ flipCode WRITE setFlipCode NOTIFY flipCodeChanged)
    Q_PROPERTY(QUrl outputFileUrl READ outputFileUrl WRITE setOutputFileUrl NOTIFY outputFileUrlChanged)

public:
    explicit Flip(QObject* parent = nullptr);
    QUrl inputFileUrl();
    int flipCode();
    QUrl outputFileUrl();

    Q_INVOKABLE void execute();

signals:
    void inputFileUrlChanged();
    void flipCodeChanged();
    void outputFileUrlChanged();

public slots:
    void setInputFileUrl(QUrl value);
    void setFlipCode(int value);
    void setOutputFileUrl(QUrl value);

private:
    QUrl m_inputFileUrl;
    int m_flipCode;
    QUrl m_outputFileUrl;
};

} // namespace flip
} // namespace qt_opencv_samples
