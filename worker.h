#ifndef WORKER_H
#define WORKER_H

#include <QString>
#include <QMap>
#include <QJsonObject>
#include <QObject>
#include <QQmlEngine>

class Worker: public QObject
{
    Q_OBJECT
    // Властивості, які будуть доступні в QML

    Q_PROPERTY(QDate startDate READ getStartDate WRITE setStartDate NOTIFY rangeChanged)
    Q_PROPERTY(QDate endDate READ getEndDate WRITE setEndDate NOTIFY rangeChanged)

    Q_PROPERTY(QString firstName READ getFirstName WRITE setFirstName NOTIFY workerChanged)
    Q_PROPERTY(QString lastName READ getLastName WRITE setLastName NOTIFY workerChanged)

    Q_PROPERTY(QString color READ getColor WRITE setColor NOTIFY colorChanged)

public:

    explicit Worker(QObject *parent = nullptr);

    QString getFirstName() const { return firstName; }
    QString getLastName() const { return lastName; }

    QDate getStartDate() const { return m_startDate; }
    QDate getEndDate() const { return m_endDate; }

    QString getColor() const { return m_color; }

    Q_INVOKABLE bool isInRange(const QDate &date) const;

    Q_INVOKABLE void handleClick(const QDate &date, Worker* worker);


public slots:
    void setFirstName(QString firstName);
    void setLastName(QString lastName);

    void setStartDate(const QDate &date);
    void setEndDate(const QDate &date);

    void setColor(const QString &c);

    //void addWorker();

signals:
    void workerChanged();
    void rangeChanged();
    void requestSave();
    void colorChanged();
private:
    QString firstName;
    QString lastName;

    QDate m_startDate;
    QDate m_endDate;

    QString m_color = "#3498db";

};

#endif // WORKER_H
