/****************************************************************************
** Meta object code from reading C++ file 'fileService.h'
**
** Created by: The Qt Meta Object Compiler version 69 (Qt 6.10.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../../fileService.h"
#include <QtCore/qmetatype.h>

#include <QtCore/qtmochelpers.h>

#include <memory>


#include <QtCore/qxptype_traits.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'fileService.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 69
#error "This file was generated using the moc from 6.10.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

#ifndef Q_CONSTINIT
#define Q_CONSTINIT
#endif

QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
QT_WARNING_DISABLE_GCC("-Wuseless-cast")
namespace {
struct qt_meta_tag_ZN11FileServiceE_t {};
} // unnamed namespace

template <> constexpr inline auto FileService::qt_create_metaobjectdata<qt_meta_tag_ZN11FileServiceE_t>()
{
    namespace QMC = QtMocConstants;
    QtMocHelpers::StringRefStorage qt_stringData {
        "FileService",
        "dataUpdated",
        "",
        "savePath",
        "path",
        "loadPath",
        "createObject",
        "Worker*",
        "worker",
        "getColorForDate",
        "date",
        "getColorForWorker",
        "firstName",
        "lastName",
        "addWorker",
        "writeResults",
        "filePath",
        "saveData",
        "loadResults",
        "deleteResults",
        "hasIncompleteBookings",
        "workersNames"
    };

    QtMocHelpers::UintData qt_methods {
        // Signal 'dataUpdated'
        QtMocHelpers::SignalData<void()>(1, 2, QMC::AccessPublic, QMetaType::Void),
        // Method 'savePath'
        QtMocHelpers::MethodData<void(const QString &)>(3, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::QString, 4 },
        }}),
        // Method 'loadPath'
        QtMocHelpers::MethodData<QString()>(5, 2, QMC::AccessPublic, QMetaType::QString),
        // Method 'createObject'
        QtMocHelpers::MethodData<void(Worker *)>(6, 2, QMC::AccessPublic, QMetaType::Void, {{
            { 0x80000000 | 7, 8 },
        }}),
        // Method 'getColorForDate'
        QtMocHelpers::MethodData<QString(QDate)>(9, 2, QMC::AccessPublic, QMetaType::QString, {{
            { QMetaType::QDate, 10 },
        }}),
        // Method 'getColorForWorker'
        QtMocHelpers::MethodData<QString(const QString, const QString)>(11, 2, QMC::AccessPublic, QMetaType::QString, {{
            { QMetaType::QString, 12 }, { QMetaType::QString, 13 },
        }}),
        // Method 'addWorker'
        QtMocHelpers::MethodData<void(const QString &, const QString &)>(14, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::QString, 12 }, { QMetaType::QString, 13 },
        }}),
        // Method 'writeResults'
        QtMocHelpers::MethodData<void(const QString &)>(15, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::QString, 16 },
        }}),
        // Method 'saveData'
        QtMocHelpers::MethodData<void(const QString &)>(17, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::QString, 16 },
        }}),
        // Method 'loadResults'
        QtMocHelpers::MethodData<void(const QString &)>(18, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::QString, 16 },
        }}),
        // Method 'deleteResults'
        QtMocHelpers::MethodData<void(const QString &)>(19, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::QString, 16 },
        }}),
        // Method 'hasIncompleteBookings'
        QtMocHelpers::MethodData<bool()>(20, 2, QMC::AccessPublic, QMetaType::Bool),
    };
    QtMocHelpers::UintData qt_properties {
        // property 'workersNames'
        QtMocHelpers::PropertyData<QStringList>(21, QMetaType::QStringList, QMC::DefaultPropertyFlags, 0),
    };
    QtMocHelpers::UintData qt_enums {
    };
    return QtMocHelpers::metaObjectData<FileService, qt_meta_tag_ZN11FileServiceE_t>(QMC::MetaObjectFlag{}, qt_stringData,
            qt_methods, qt_properties, qt_enums);
}
Q_CONSTINIT const QMetaObject FileService::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN11FileServiceE_t>.stringdata,
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN11FileServiceE_t>.data,
    qt_static_metacall,
    nullptr,
    qt_staticMetaObjectRelocatingContent<qt_meta_tag_ZN11FileServiceE_t>.metaTypes,
    nullptr
} };

void FileService::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    auto *_t = static_cast<FileService *>(_o);
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: _t->dataUpdated(); break;
        case 1: _t->savePath((*reinterpret_cast<std::add_pointer_t<QString>>(_a[1]))); break;
        case 2: { QString _r = _t->loadPath();
            if (_a[0]) *reinterpret_cast<QString*>(_a[0]) = std::move(_r); }  break;
        case 3: _t->createObject((*reinterpret_cast<std::add_pointer_t<Worker*>>(_a[1]))); break;
        case 4: { QString _r = _t->getColorForDate((*reinterpret_cast<std::add_pointer_t<QDate>>(_a[1])));
            if (_a[0]) *reinterpret_cast<QString*>(_a[0]) = std::move(_r); }  break;
        case 5: { QString _r = _t->getColorForWorker((*reinterpret_cast<std::add_pointer_t<QString>>(_a[1])),(*reinterpret_cast<std::add_pointer_t<QString>>(_a[2])));
            if (_a[0]) *reinterpret_cast<QString*>(_a[0]) = std::move(_r); }  break;
        case 6: _t->addWorker((*reinterpret_cast<std::add_pointer_t<QString>>(_a[1])),(*reinterpret_cast<std::add_pointer_t<QString>>(_a[2]))); break;
        case 7: _t->writeResults((*reinterpret_cast<std::add_pointer_t<QString>>(_a[1]))); break;
        case 8: _t->saveData((*reinterpret_cast<std::add_pointer_t<QString>>(_a[1]))); break;
        case 9: _t->loadResults((*reinterpret_cast<std::add_pointer_t<QString>>(_a[1]))); break;
        case 10: _t->deleteResults((*reinterpret_cast<std::add_pointer_t<QString>>(_a[1]))); break;
        case 11: { bool _r = _t->hasIncompleteBookings();
            if (_a[0]) *reinterpret_cast<bool*>(_a[0]) = std::move(_r); }  break;
        default: ;
        }
    }
    if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
        case 3:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
            case 0:
                *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType::fromType< Worker* >(); break;
            }
            break;
        }
    }
    if (_c == QMetaObject::IndexOfMethod) {
        if (QtMocHelpers::indexOfMethod<void (FileService::*)()>(_a, &FileService::dataUpdated, 0))
            return;
    }
    if (_c == QMetaObject::ReadProperty) {
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast<QStringList*>(_v) = _t->workersNames(); break;
        default: break;
        }
    }
}

const QMetaObject *FileService::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *FileService::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_staticMetaObjectStaticContent<qt_meta_tag_ZN11FileServiceE_t>.strings))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int FileService::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 12)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 12;
    }
    if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 12)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 12;
    }
    if (_c == QMetaObject::ReadProperty || _c == QMetaObject::WriteProperty
            || _c == QMetaObject::ResetProperty || _c == QMetaObject::BindableProperty
            || _c == QMetaObject::RegisterPropertyMetaType) {
        qt_static_metacall(this, _c, _id, _a);
        _id -= 1;
    }
    return _id;
}

// SIGNAL 0
void FileService::dataUpdated()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}
QT_WARNING_POP
