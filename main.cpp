#include <QGuiApplication>
#include <QQmlContext>
#include <QQmlApplicationEngine>
#include <QtQuickControls2/QQuickStyle>
#include <QNetworkAccessManager>
#include "worker.h"
#include "fileService.h"
#include "networkservice.h"
int main(int argc, char *argv[])
{
    QQuickStyle::setStyle("Fusion");
    QGuiApplication app(argc, argv);

    Worker worker;
    FileService fileService;
    NetworkService networkService;

    QQmlApplicationEngine engine;
    engine.rootContext()->setContextProperty("fileService", &fileService);
    engine.rootContext()->setContextProperty("Worker", &worker);
    engine.rootContext()->setContextProperty("networkService", &networkService);
    QObject::connect(
        &engine,
        &QQmlApplicationEngine::objectCreationFailed,
        &app,
        []() { QCoreApplication::exit(-1); },
        Qt::QueuedConnection);
    engine.loadFromModule("Calendar", "Main");

    return app.exec();
}
