#include <QGuiApplication>
#include <QQmlContext>
#include <QQmlApplicationEngine>
#include <QNetworkAccessManager>
#include "D:\Diana\nure\CPPro\course work\calendar\worker.h"
#include "D:\Diana\nure\CPPro\course work\calendar\fileService.h"
#include "D:\Diana\nure\CPPro\course work\calendar\networkservice.h"
int main(int argc, char *argv[])
{
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
