
#include "fileService.h"

void FileService::createObject(Worker* worker) {
    if (!worker) return;

    bool found = false;
    for (int i = 0; i < m_bookings.size(); ++i) {

        if (m_bookings[i].firstName == worker->getFirstName() &&
            m_bookings[i].lastName == worker->getLastName()) {

            m_bookings[i].start = worker->getStartDate();
            m_bookings[i].end = worker->getEndDate();
            m_bookings[i].color = worker->getColor();
            found = true;
            break;
        }
    }

    if (!found) {
        Booking b;
        b.firstName = worker->getFirstName();
        b.lastName = worker->getLastName();
        b.start = worker->getStartDate();
        b.end = worker->getEndDate();
        b.color = worker->getColor();
        m_bookings.append(b);
    }

    emit dataUpdated();
    saveData("data.json");
}
void FileService::updateColorForIntersection(){
    int r = QRandomGenerator::global()->bounded(256);
    int g = QRandomGenerator::global()->bounded(256);
    int bl = QRandomGenerator::global()->bounded(256);
     m_colorForInter = QColor(r, g, bl).name();
}

QString FileService::getColorForDate(QDate date) {
    int count = 0;
    QString lastFoundColor = "";


    for (const auto &b : m_bookings) {
        if (date >= b.start && date <= b.end) {
            count++;
            lastFoundColor = b.color;
        }
    }
    if (count > 1) {
        if (m_colorForInter.isEmpty()) {
            updateColorForIntersection();
        }

        return m_colorForInter;
    }

    else if (count == 1) {
        return lastFoundColor.isEmpty() ? "transperent" : lastFoundColor;
    }
    return "transparent";
}
QString FileService::getColorForWorker(const QString firstName, const QString lastName){
    for (int i = m_bookings.size() - 1; i >= 0; --i) {
        if (m_bookings[i].firstName == firstName && m_bookings[i].lastName == lastName) {
            return m_bookings[i].color;
        }
    }

    return "transparent";
}
void FileService::addWorker(const QString& firstName, const QString& lastName) {
    Booking b;
    b.firstName = firstName;
    b.lastName = lastName;
    int r = QRandomGenerator::global()->bounded(256);
    int g = QRandomGenerator::global()->bounded(256);
    int bl = QRandomGenerator::global()->bounded(256);
    b.color = QColor(r, g, bl).name();
    m_bookings.append(b);

    emit dataUpdated();

    saveData("data.json");
    updateNamesList();
}
void FileService::updateNamesList() {
    m_workersNames.clear();
    for (const auto &b : m_bookings) {
        QString fullName = b.firstName + " " + b.lastName;
        if (!m_workersNames.contains(fullName)) {
            m_workersNames.append(fullName);
        }
    }
    emit dataUpdated();
}
void FileService::saveData(const QString& filePath) {
    QFile file(filePath);
    if (!file.open(QIODevice::WriteOnly)) return;

    QJsonObject root;
    QJsonArray workersArray;
    QJsonArray bookingsArray;

    for (const auto &b : m_bookings) {
        QJsonObject bObj;
        if (!b.firstName.isEmpty() &&
            !b.lastName.isEmpty() )
           // &&b.start.isValid()
          // && b.end.isValid())
        {
        bObj["firstName"] = b.firstName;
        bObj["lastName"] = b.lastName;
        bObj["start"] = b.start.toString("yyyy-MM-dd");
        bObj["end"] = b.end.toString("yyyy-MM-dd");
        bObj["color"] = b.color;
        bookingsArray.append(bObj);
        }
    }

    root["bookings"] = bookingsArray;

    QJsonDocument doc(root);
    file.write(doc.toJson());
    file.close();
}
void FileService::loadResults(const QString& filePath){
    QFile file(filePath);

    if (!file.open(QIODevice::ReadOnly))
    {
        qCritical() << "Не вдалося відкрити файл для читання:" << file.errorString();
        return;
    }

    QByteArray data = file.readAll();
    QJsonDocument doc = QJsonDocument::fromJson(data);
    QJsonObject root = doc.object();

QJsonArray array = root["bookings"].toArray();
    m_bookings.clear();

    for (int i = 0; i < array.size(); ++i) {
        QJsonObject obj = array[i].toObject();
        Booking b;
        b.firstName = obj["firstName"].toString();
        b.lastName = obj["lastName"].toString();
        b.start = QDate::fromString(obj["start"].toString(), "yyyy-MM-dd");
        b.end = QDate::fromString(obj["end"].toString(), "yyyy-MM-dd");
        b.color = obj["color"].toString();

        m_bookings.append(b);
    }
    file.close();
    updateNamesList();
    emit dataUpdated();
}
void FileService::writeResults(const QString& filePath)
{
    QFile file(filePath);

    if (!file.open(QIODevice::WriteOnly | QIODevice::Text))
    {
        qCritical() << "Не вдалося відкрити файл для запису:" << file.errorString();
        return;
    }

    QTextStream out(&file);
    out.setEncoding(QStringConverter::Utf8);

    for (const auto &b : m_bookings) {

        out << "ПІБ: " << b.firstName<<" "<< b.lastName<< "\n";
        out << "Дата початку: " << b.start.toString("dd.MM.yyyy") << "\n";
        out << "Дата кінця: " << b.end.toString("dd.MM.yyyy") << "\n";
        out << "----------------------------\n";

        out << '\n';
    }

    file.close();
    out.setEncoding(QStringConverter::Utf8);
    out << "Запис завершено" << Qt::endl;
}
void FileService::deleteResults(const QString& filePath){
    QFile file(filePath);
    if (file.exists()) {
        file.remove();
    }
    m_bookings.clear();
    updateNamesList();
    emit dataUpdated();

    qDebug() << "Дані видалено з пам'яті та файлу.";
}

void FileService::savePath(const QString& path) {
    QSettings settings("nure", "BookingApp");
    settings.setValue("reportPath", path);
}

QString FileService::loadPath() {
    QSettings settings("nure", "BookingApp");
    return settings.value("reportPath", "").toString();
}
bool FileService::hasIncompleteBookings()
{
    for (const auto &b : m_bookings) {

        if (!b.start.isValid() || !b.end.isValid()) {
            return true;
        }
    }

    return false;
}
