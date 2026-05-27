#include "worker.h"
#include "fileService.h"
#include <QFile>
#include <QTextStream>
#include <QDebug>

Worker::Worker(QObject *parent) : QObject(parent) {

}
void Worker::setFirstName(QString firstName){
    if (this->firstName != firstName) {
        this->firstName = firstName;
        emit workerChanged();
    }
}
void Worker::setLastName(QString lastName){
    if (this->lastName != lastName) {
    this->lastName = lastName;
        emit workerChanged();
    }
}
void Worker::setStartDate(const QDate &date){
    if (m_startDate != date) {
        m_startDate = date;
        emit rangeChanged();
        qDebug() << "Start date selected:" << m_startDate;
    }
}
void Worker::setEndDate(const QDate &date){
    if (m_endDate != date) {
        m_endDate = date;
        emit rangeChanged();
        qDebug() << "End date selected:" << m_endDate;
    }
}
bool Worker::isInRange(const QDate &date) const {
    if (!m_startDate.isValid())
        return false;
    if (!m_endDate.isValid())
        return date == m_startDate;

    return (date >= m_startDate && date <= m_endDate);
}
void Worker::handleClick(const QDate &date, Worker* worker){

    if (!m_startDate.isValid() || (m_startDate.isValid() && m_endDate.isValid())) {
        setStartDate(date);
        setEndDate(QDate());
    } else {
        if (date < m_startDate) {
            setStartDate(date);
        } else {
            setEndDate(date);
                emit requestSave();

        }
    }

    emit rangeChanged();
}

void Worker::setColor(const QString &c) {
    if(m_color != c) {
        m_color = c;
        emit colorChanged();
    }
}
