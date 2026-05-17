/****************************************************************************
** Meta object code from reading C++ file 'calendar.h'
**
** Created by: The Qt Meta Object Compiler version 69 (Qt 6.10.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../../calendar.h"
#include <QtCore/qmetatype.h>

#include <QtCore/qtmochelpers.h>

#include <memory>


#include <QtCore/qxptype_traits.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'calendar.h' doesn't include <QObject>."
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
struct qt_meta_tag_ZN8CalendarE_t {};
} // unnamed namespace

template <> constexpr inline auto Calendar::qt_create_metaobjectdata<qt_meta_tag_ZN8CalendarE_t>()
{
    namespace QMC = QtMocConstants;
    QtMocHelpers::StringRefStorage qt_stringData {
        "Calendar",
        "rangeChanged",
        "",
        "setStartDate",
        "date",
        "setEndDate",
        "isInRange",
        "handleClick",
        "startDate",
        "endDate"
    };

    QtMocHelpers::UintData qt_methods {
        // Signal 'rangeChanged'
        QtMocHelpers::SignalData<void()>(1, 2, QMC::AccessPublic, QMetaType::Void),
        // Slot 'setStartDate'
        QtMocHelpers::SlotData<void(const QDate &)>(3, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::QDate, 4 },
        }}),
        // Slot 'setEndDate'
        QtMocHelpers::SlotData<void(const QDate &)>(5, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::QDate, 4 },
        }}),
        // Method 'isInRange'
        QtMocHelpers::MethodData<bool(const QDate &) const>(6, 2, QMC::AccessPublic, QMetaType::Bool, {{
            { QMetaType::QDate, 4 },
        }}),
        // Method 'handleClick'
        QtMocHelpers::MethodData<void(const QDate &)>(7, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::QDate, 4 },
        }}),
    };
    QtMocHelpers::UintData qt_properties {
        // property 'startDate'
        QtMocHelpers::PropertyData<QDate>(8, QMetaType::QDate, QMC::DefaultPropertyFlags | QMC::Writable | QMC::StdCppSet, 0),
        // property 'endDate'
        QtMocHelpers::PropertyData<QDate>(9, QMetaType::QDate, QMC::DefaultPropertyFlags | QMC::Writable | QMC::StdCppSet, 0),
    };
    QtMocHelpers::UintData qt_enums {
    };
    return QtMocHelpers::metaObjectData<Calendar, qt_meta_tag_ZN8CalendarE_t>(QMC::MetaObjectFlag{}, qt_stringData,
            qt_methods, qt_properties, qt_enums);
}
Q_CONSTINIT const QMetaObject Calendar::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN8CalendarE_t>.stringdata,
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN8CalendarE_t>.data,
    qt_static_metacall,
    nullptr,
    qt_staticMetaObjectRelocatingContent<qt_meta_tag_ZN8CalendarE_t>.metaTypes,
    nullptr
} };

void Calendar::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    auto *_t = static_cast<Calendar *>(_o);
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: _t->rangeChanged(); break;
        case 1: _t->setStartDate((*reinterpret_cast<std::add_pointer_t<QDate>>(_a[1]))); break;
        case 2: _t->setEndDate((*reinterpret_cast<std::add_pointer_t<QDate>>(_a[1]))); break;
        case 3: { bool _r = _t->isInRange((*reinterpret_cast<std::add_pointer_t<QDate>>(_a[1])));
            if (_a[0]) *reinterpret_cast<bool*>(_a[0]) = std::move(_r); }  break;
        case 4: _t->handleClick((*reinterpret_cast<std::add_pointer_t<QDate>>(_a[1]))); break;
        default: ;
        }
    }
    if (_c == QMetaObject::IndexOfMethod) {
        if (QtMocHelpers::indexOfMethod<void (Calendar::*)()>(_a, &Calendar::rangeChanged, 0))
            return;
    }
    if (_c == QMetaObject::ReadProperty) {
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast<QDate*>(_v) = _t->getStartDate(); break;
        case 1: *reinterpret_cast<QDate*>(_v) = _t->getEndDate(); break;
        default: break;
        }
    }
    if (_c == QMetaObject::WriteProperty) {
        void *_v = _a[0];
        switch (_id) {
        case 0: _t->setStartDate(*reinterpret_cast<QDate*>(_v)); break;
        case 1: _t->setEndDate(*reinterpret_cast<QDate*>(_v)); break;
        default: break;
        }
    }
}

const QMetaObject *Calendar::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Calendar::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_staticMetaObjectStaticContent<qt_meta_tag_ZN8CalendarE_t>.strings))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int Calendar::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 5)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 5;
    }
    if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 5)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 5;
    }
    if (_c == QMetaObject::ReadProperty || _c == QMetaObject::WriteProperty
            || _c == QMetaObject::ResetProperty || _c == QMetaObject::BindableProperty
            || _c == QMetaObject::RegisterPropertyMetaType) {
        qt_static_metacall(this, _c, _id, _a);
        _id -= 2;
    }
    return _id;
}

// SIGNAL 0
void Calendar::rangeChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}
QT_WARNING_POP
