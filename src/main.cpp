#include "qt_opencv_samples/flip/Flip.h"
#include "qt_opencv_samples/rotation/Rotation.h"
#include <QGuiApplication>
#include <QQmlApplicationEngine>

static void qmlRegistration()
{
    using qt_opencv_samples::flip::Flip;
    using qt_opencv_samples::rotation::Rotation;

    qmlRegisterType<Flip>("QtOpenCVSamples", 1, 0, "Flip");
    qmlRegisterType<Rotation>("QtOpenCVSamples", 1, 0, "Rotation");
}

int main(int argc, char* argv[])
{
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
    QGuiApplication app(argc, argv);
    app.setOrganizationName("None");
    app.setOrganizationDomain("None");

    qmlRegistration();

    QQmlApplicationEngine engine;
    engine.addImportPath(QStringLiteral("qrc:/"));
    engine.load(QUrl(QStringLiteral("qrc:/MainWindow.qml")));
    if (engine.rootObjects().isEmpty()) {
        return -1;
    }

    return app.exec();
}
