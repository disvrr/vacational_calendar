/****************************************************************************
** Meta object code from reading C++ file 'worker.h'
**
** Created by: The Qt Meta Object Compiler version 69 (Qt 6.10.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../../worker.h"
#include <QtCore/qmetatype.h>

#include <QtCore/qtmochelpers.h>

#include <memory>


#include <QtCore/qxptype_traits.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'worker.h' doesn't include <QObject>."
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
struct qt_meta_tag_ZN6WorkerE_t {};
} // unnamed namespace

template <> constexpr inline auto Worker::qt_create_metaobjectdata<qt_meta_tag_ZN6WorkerE_t>()
{
    namespace QMC = QtMocConstants;
    QtMocHelpers::StringRefStorage qt_stringData {
        "Worker",
        "workerChanged",
        "",
        "rangeChanged",
        "requestSave",
        "colorChanged",
        "setFirstName",
        "firstName",
        "setLastName",
        "lastName",
        "setStartDate",
        "date",
        "setEndDate",
        "setColor",
        "c",
        "isInRange",
        "handleClick",
        "Worker*",
        "worker",
        "startDate",
        "endDate",
        "color"
    };

    QtMocHelpers::UintData qt_methods {
        // Signal 'workerChanged'
        QtMocHelpers::SignalData<void()>(1, 2, QMC::AccessPublic, QMetaType::Void),
        // Signal 'rangeChanged'
        QtMocHelpers::SignalData<void()>(3, 2, QMC::AccessPublic, QMetaType::Void),
        // Signal 'requestSave'
        QtMocHelpers::SignalData<void()>(4, 2, QMC::AccessPublic, QMetaType::Void),
        // Signal 'colorChanged'
        QtMocHelpers::SignalData<void()>(5, 2, QMC::AccessPublic, QMetaType::Void),
        // Slot 'setFirstName'
        QtMocHelpers::SlotData<void(QString)>(6, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::QString, 7 },
        }}),
        // Slot 'setLastName'
        QtMocHelpers::SlotData<void(QString)>(8, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::QString, 9 },
        }}),
        // Slot 'setStartDate'
        QtMocHelpers::SlotData<void(const QDate &)>(10, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::QDate, 11 },
        }}),
        // Slot 'setEndDate'
        QtMocHelpers::SlotData<void(const QDate &)>(12, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::QDate, 11 },
        }}),
        // Slot 'setColor'
        QtMocHelpers::SlotData<void(const QString &)>(13, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::QString, 14 },
        }}),
        // Method 'isInRange'
        QtMocHelpers::MethodData<bool(const QDate &) const>(15, 2, QMC::AccessPublic, QMetaType::Bool, {{
            { QMetaType::QDate, 11 },
        }}),
        // Method 'handleClick'
        QtMocHelpers::MethodData<void(const QDate &, Worker *)>(16, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::QDate, 11 }, { 0x80000000 | 17, 18 },
        }}),
    };
    QtMocHelpers::UintData qt_properties {
        // property 'startDate'
        QtMocHelpers::PropertyData<QDate>(19, QMetaType::QDate, QMC::DefaultPropertyFlags | QMC::Writable | QMC::StdCppSet, 1),
        // property 'endDate'
        QtMocHelpers::PropertyData<QDate>(20, QMetaType::QDate, QMC::DefaultPropertyFlags | QMC::Writable | QMC::StdCppSet, 1),
        // property 'firstName'
        QtMocHelpers::PropertyData<QString>(7, QMetaType::QString, QMC::DefaultPropertyFlags | QMC::Writable | QMC::StdCppSet, 0),
        // property 'lastName'
        QtMocHelpers::PropertyData<QString>(9, QMetaType::QString, QMC::DefaultPropertyFlags | QMC::Writable | QMC::StdCppSet, 0),
        // property 'color'
        QtMocHelpers::PropertyData<QString>(21, QMetaType::QString, QMC::DefaultPropertyFlags | QMC::Writable | QMC::StdCppSet, 3),
    };
    QtMocHelpers::UintData qt_enums {
    };
    return QtMocHelpers::metaObjectData<Worker, qt_meta_tag_ZN6WorkerE_t>(QMC::MetaObjectFlag{}, qt_stringData,
            qt_methods, qt_properties, qt_enums);
}
Q_CONSTINIT const QMetaObject Worker::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN6WorkerE_t>.stringdata,
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN6WorkerE_t>.data,
    qt_static_metacall,
    nullptr,
    qt_staticMetaObjectRelocatingContent<qt_meta_tag_ZN6WorkerE_t>.metaTypes,
    nullptr
} };

void Worker::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    auto *_t = static_cast<Worker *>(_o);
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: _t->workerChanged(); break;
        case 1: _t->rangeChanged(); break;
        case 2: _t->requestSave(); break;
        case 3: _t->colorChanged(); break;
        case 4: _t->setFirstName((*reinterpret_cast<std::add_pointer_t<QString>>(_a[1]))); break;
        case 5: _t->setLastName((*reinterpret_cast<std::add_pointer_t<QString>>(_a[1]))); break;
        case 6: _t->setStartDate((*reinterpret_cast<std::add_pointer_t<QDate>>(_a[1]))); break;
        case 7: _t->setEndDate((*reinterpret_cast<std::add_pointer_t<QDate>>(_a[1]))); break;
        case 8: _t->setColor((*reinterpret_cast<std::add_pointer_t<QString>>(_a[1]))); break;
        case 9: { bool _r = _t->isInRange((*reinterpret_cast<std::add_pointer_t<QDate>>(_a[1])));
            if (_a[0]) *reinterpret_cast<bool*>(_a[0]) = std::move(_r); }  break;
        case 10: _t->handleClick((*reinterpret_cast<std::add_pointer_t<QDate>>(_a[1])),(*reinterpret_cast<std::add_pointer_t<Worker*>>(_a[2]))); break;
        default: ;
        }
    }
    if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
        case 10:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
            case 1:
                *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType::fromType< Worker* >(); break;
            }
            break;
        }
    }
    if (_c == QMetaObject::IndexOfMethod) {
        if (QtMocHelpers::indexOfMethod<void (Worker::*)()>(_a, &Worker::workerChanged, 0))
            return;
        if (QtMocHelpers::indexOfMethod<void (Worker::*)()>(_a, &Worker::rangeChanged, 1))
            return;
        if (QtMocHelpers::indexOfMethod<void (Worker::*)()>(_a, &Worker::requestSave, 2))
            return;
        if (QtMocHelpers::indexOfMethod<void (Worker::*)()>(_a, &Worker::colorChanged, 3))
            return;
    }
    if (_c == QMetaObject::ReadProperty) {
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast<QDate*>(_v) = _t->getStartDate(); break;
        case 1: *reinterpret_cast<QDate*>(_v) = _t->getEndDate(); break;
        case 2: *reinterpret_cast<QString*>(_v) = _t->getFirstName(); break;
        case 3: *reinterpret_cast<QString*>(_v) = _t->getLastName(); break;
        case 4: *reinterpret_cast<QString*>(_v) = _t->getColor(); break;
        default: break;
        }
    }
    if (_c == QMetaObject::WriteProperty) {
        void *_v = _a[0];
        switch (_id) {
        case 0: _t->setStartDate(*reinterpret_cast<QDate*>(_v)); break;
        case 1: _t->setEndDate(*reinterpret_cast<QDate*>(_v)); break;
        case 2: _t->setFirstName(*reinterpret_cast<QString*>(_v)); break;
        case 3: _t->setLastName(*reinterpret_cast<QString*>(_v)); break;
        case 4: _t->setColor(*reinterpret_cast<QString*>(_v)); break;
        default: break;
        }
    }
}

const QMetaObject *Worker::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Worker::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_staticMetaObjectStaticContent<qt_meta_tag_ZN6WorkerE_t>.strings))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int Worker::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 11)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 11;
    }
    if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 11)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 11;
    }
    if (_c == QMetaObject::ReadProperty || _c == QMetaObject::WriteProperty
            || _c == QMetaObject::ResetProperty || _c == QMetaObject::BindableProperty
            || _c == QMetaObject::RegisterPropertyMetaType) {
        qt_static_metacall(this, _c, _id, _a);
        _id -= 5;
    }
    return _id;
}

// SIGNAL 0
void Worker::workerChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void Worker::rangeChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}

// SIGNAL 2
void Worker::requestSave()
{
    QMetaObject::activate(this, &staticMetaObject, 2, nullptr);
}

// SIGNAL 3
void Worker::colorChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 3, nullptr);
}
QT_WARNING_POP
