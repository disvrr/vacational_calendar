#ifndef NETWORKSERVICE_H
#define NETWORKSERVICE_H

#include <QObject>

class NetworkService : public QObject {
    Q_OBJECT
public:
    explicit NetworkService(QObject *parent = nullptr);
    Q_INVOKABLE void fetchTime();

signals:
    void timeReceived(QString timeString);
};

#endif // NETWORKSERVICE_H
