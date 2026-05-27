#ifndef HEADER_H
#define HEADER_H
#include <QObject>
#include <QQmlEngine>

class Backend : public QObject
{
    Q_OBJECT
    QML_ELEMENT
    QML_SINGLETON

public:
    Q_INVOKABLE void doStuff();
};
#endif // HEADER_H
