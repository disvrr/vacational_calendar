#ifndef FILESERVICE_H
#define FILESERVICE_H

#include <QString>
#include <QList>
#include <QJsonObject>
#include <QJsonDocument>
#include <QJsonArray>
#include <QObject>
#include <QQmlEngine>
#include <QFile>
#include <QSettings>
#include <QColor>
#include <QRandomGenerator>
#include "worker.h"


class FileService : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QStringList workersNames READ workersNames NOTIFY dataUpdated)

public:

    explicit FileService(QObject *parent = nullptr){}
    Q_INVOKABLE void savePath(const QString& path);
    Q_INVOKABLE QString loadPath();

    Q_INVOKABLE void createObject(Worker* worker);
    Q_INVOKABLE QString getColorForDate(QDate date);
    Q_INVOKABLE QString getColorForWorker(const QString firstName, const QString lastName);
    Q_INVOKABLE void addWorker(const QString& firstName, const QString& lastName);
    Q_INVOKABLE void writeResults(const QString& filePath);
    Q_INVOKABLE void saveData(const QString& filePath);
    Q_INVOKABLE void loadResults(const QString& filePath);
    Q_INVOKABLE void deleteResults(const QString& filePath);
    Q_INVOKABLE bool hasIncompleteBookings();

    QStringList workersNames() const { return m_workersNames; }
public slots:


signals:
void dataUpdated();
private:
    struct Booking {
        QString firstName;
        QString lastName;
        QDate start;
        QDate end;
        QString color;
    };

    QStringList m_workersNames;
    QList<Booking> m_bookings;
    void updateNamesList();

};

#endif // FILESERVICE_H





