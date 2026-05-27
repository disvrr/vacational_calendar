#include "networkservice.h"
#include <QTime>

NetworkService::NetworkService(QObject *parent) : QObject(parent) {}

void NetworkService::fetchTime() {
    emit timeReceived(QTime::currentTime().toString("HH:mm"));
}
