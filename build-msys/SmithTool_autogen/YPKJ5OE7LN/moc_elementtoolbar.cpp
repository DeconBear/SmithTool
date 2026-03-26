/****************************************************************************
** Meta object code from reading C++ file 'elementtoolbar.h'
**
** Created by: The Qt Meta Object Compiler version 69 (Qt 6.10.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../src/ui/elementtoolbar.h"
#include <QtGui/qtextcursor.h>
#include <QtCore/qmetatype.h>

#include <QtCore/qtmochelpers.h>

#include <memory>


#include <QtCore/qxptype_traits.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'elementtoolbar.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 69
#error "This file was generated using the moc from 6.10.0. It"
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
struct qt_meta_tag_ZN9SmithTool14ElementToolbarE_t {};
} // unnamed namespace

template <> constexpr inline auto SmithTool::ElementToolbar::qt_create_metaobjectdata<qt_meta_tag_ZN9SmithTool14ElementToolbarE_t>()
{
    namespace QMC = QtMocConstants;
    QtMocHelpers::StringRefStorage qt_stringData {
        "SmithTool::ElementToolbar",
        "addSeriesInductor",
        "",
        "value_henry",
        "addSeriesCapacitor",
        "value_farad",
        "addSeriesResistor",
        "value_ohm",
        "addShuntInductor",
        "addShuntCapacitor",
        "addShuntResistor",
        "selectPointForElement",
        "ComponentType",
        "type",
        "ConnectionType",
        "connection",
        "clearAllElements",
        "undoLastElement",
        "onAddSeriesL",
        "onAddSeriesC",
        "onAddSeriesR",
        "onAddShuntL",
        "onAddShuntC",
        "onAddShuntR",
        "onUnitChanged",
        "index"
    };

    QtMocHelpers::UintData qt_methods {
        // Signal 'addSeriesInductor'
        QtMocHelpers::SignalData<void(double)>(1, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::Double, 3 },
        }}),
        // Signal 'addSeriesCapacitor'
        QtMocHelpers::SignalData<void(double)>(4, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::Double, 5 },
        }}),
        // Signal 'addSeriesResistor'
        QtMocHelpers::SignalData<void(double)>(6, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::Double, 7 },
        }}),
        // Signal 'addShuntInductor'
        QtMocHelpers::SignalData<void(double)>(8, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::Double, 3 },
        }}),
        // Signal 'addShuntCapacitor'
        QtMocHelpers::SignalData<void(double)>(9, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::Double, 5 },
        }}),
        // Signal 'addShuntResistor'
        QtMocHelpers::SignalData<void(double)>(10, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::Double, 7 },
        }}),
        // Signal 'selectPointForElement'
        QtMocHelpers::SignalData<void(ComponentType, ConnectionType)>(11, 2, QMC::AccessPublic, QMetaType::Void, {{
            { 0x80000000 | 12, 13 }, { 0x80000000 | 14, 15 },
        }}),
        // Signal 'clearAllElements'
        QtMocHelpers::SignalData<void()>(16, 2, QMC::AccessPublic, QMetaType::Void),
        // Signal 'undoLastElement'
        QtMocHelpers::SignalData<void()>(17, 2, QMC::AccessPublic, QMetaType::Void),
        // Slot 'onAddSeriesL'
        QtMocHelpers::SlotData<void()>(18, 2, QMC::AccessPrivate, QMetaType::Void),
        // Slot 'onAddSeriesC'
        QtMocHelpers::SlotData<void()>(19, 2, QMC::AccessPrivate, QMetaType::Void),
        // Slot 'onAddSeriesR'
        QtMocHelpers::SlotData<void()>(20, 2, QMC::AccessPrivate, QMetaType::Void),
        // Slot 'onAddShuntL'
        QtMocHelpers::SlotData<void()>(21, 2, QMC::AccessPrivate, QMetaType::Void),
        // Slot 'onAddShuntC'
        QtMocHelpers::SlotData<void()>(22, 2, QMC::AccessPrivate, QMetaType::Void),
        // Slot 'onAddShuntR'
        QtMocHelpers::SlotData<void()>(23, 2, QMC::AccessPrivate, QMetaType::Void),
        // Slot 'onUnitChanged'
        QtMocHelpers::SlotData<void(int)>(24, 2, QMC::AccessPrivate, QMetaType::Void, {{
            { QMetaType::Int, 25 },
        }}),
    };
    QtMocHelpers::UintData qt_properties {
    };
    QtMocHelpers::UintData qt_enums {
    };
    return QtMocHelpers::metaObjectData<ElementToolbar, qt_meta_tag_ZN9SmithTool14ElementToolbarE_t>(QMC::MetaObjectFlag{}, qt_stringData,
            qt_methods, qt_properties, qt_enums);
}
Q_CONSTINIT const QMetaObject SmithTool::ElementToolbar::staticMetaObject = { {
    QMetaObject::SuperData::link<QToolBar::staticMetaObject>(),
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN9SmithTool14ElementToolbarE_t>.stringdata,
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN9SmithTool14ElementToolbarE_t>.data,
    qt_static_metacall,
    nullptr,
    qt_staticMetaObjectRelocatingContent<qt_meta_tag_ZN9SmithTool14ElementToolbarE_t>.metaTypes,
    nullptr
} };

void SmithTool::ElementToolbar::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    auto *_t = static_cast<ElementToolbar *>(_o);
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: _t->addSeriesInductor((*reinterpret_cast<std::add_pointer_t<double>>(_a[1]))); break;
        case 1: _t->addSeriesCapacitor((*reinterpret_cast<std::add_pointer_t<double>>(_a[1]))); break;
        case 2: _t->addSeriesResistor((*reinterpret_cast<std::add_pointer_t<double>>(_a[1]))); break;
        case 3: _t->addShuntInductor((*reinterpret_cast<std::add_pointer_t<double>>(_a[1]))); break;
        case 4: _t->addShuntCapacitor((*reinterpret_cast<std::add_pointer_t<double>>(_a[1]))); break;
        case 5: _t->addShuntResistor((*reinterpret_cast<std::add_pointer_t<double>>(_a[1]))); break;
        case 6: _t->selectPointForElement((*reinterpret_cast<std::add_pointer_t<ComponentType>>(_a[1])),(*reinterpret_cast<std::add_pointer_t<ConnectionType>>(_a[2]))); break;
        case 7: _t->clearAllElements(); break;
        case 8: _t->undoLastElement(); break;
        case 9: _t->onAddSeriesL(); break;
        case 10: _t->onAddSeriesC(); break;
        case 11: _t->onAddSeriesR(); break;
        case 12: _t->onAddShuntL(); break;
        case 13: _t->onAddShuntC(); break;
        case 14: _t->onAddShuntR(); break;
        case 15: _t->onUnitChanged((*reinterpret_cast<std::add_pointer_t<int>>(_a[1]))); break;
        default: ;
        }
    }
    if (_c == QMetaObject::IndexOfMethod) {
        if (QtMocHelpers::indexOfMethod<void (ElementToolbar::*)(double )>(_a, &ElementToolbar::addSeriesInductor, 0))
            return;
        if (QtMocHelpers::indexOfMethod<void (ElementToolbar::*)(double )>(_a, &ElementToolbar::addSeriesCapacitor, 1))
            return;
        if (QtMocHelpers::indexOfMethod<void (ElementToolbar::*)(double )>(_a, &ElementToolbar::addSeriesResistor, 2))
            return;
        if (QtMocHelpers::indexOfMethod<void (ElementToolbar::*)(double )>(_a, &ElementToolbar::addShuntInductor, 3))
            return;
        if (QtMocHelpers::indexOfMethod<void (ElementToolbar::*)(double )>(_a, &ElementToolbar::addShuntCapacitor, 4))
            return;
        if (QtMocHelpers::indexOfMethod<void (ElementToolbar::*)(double )>(_a, &ElementToolbar::addShuntResistor, 5))
            return;
        if (QtMocHelpers::indexOfMethod<void (ElementToolbar::*)(ComponentType , ConnectionType )>(_a, &ElementToolbar::selectPointForElement, 6))
            return;
        if (QtMocHelpers::indexOfMethod<void (ElementToolbar::*)()>(_a, &ElementToolbar::clearAllElements, 7))
            return;
        if (QtMocHelpers::indexOfMethod<void (ElementToolbar::*)()>(_a, &ElementToolbar::undoLastElement, 8))
            return;
    }
}

const QMetaObject *SmithTool::ElementToolbar::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *SmithTool::ElementToolbar::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_staticMetaObjectStaticContent<qt_meta_tag_ZN9SmithTool14ElementToolbarE_t>.strings))
        return static_cast<void*>(this);
    return QToolBar::qt_metacast(_clname);
}

int SmithTool::ElementToolbar::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QToolBar::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 16)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 16;
    }
    if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 16)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 16;
    }
    return _id;
}

// SIGNAL 0
void SmithTool::ElementToolbar::addSeriesInductor(double _t1)
{
    QMetaObject::activate<void>(this, &staticMetaObject, 0, nullptr, _t1);
}

// SIGNAL 1
void SmithTool::ElementToolbar::addSeriesCapacitor(double _t1)
{
    QMetaObject::activate<void>(this, &staticMetaObject, 1, nullptr, _t1);
}

// SIGNAL 2
void SmithTool::ElementToolbar::addSeriesResistor(double _t1)
{
    QMetaObject::activate<void>(this, &staticMetaObject, 2, nullptr, _t1);
}

// SIGNAL 3
void SmithTool::ElementToolbar::addShuntInductor(double _t1)
{
    QMetaObject::activate<void>(this, &staticMetaObject, 3, nullptr, _t1);
}

// SIGNAL 4
void SmithTool::ElementToolbar::addShuntCapacitor(double _t1)
{
    QMetaObject::activate<void>(this, &staticMetaObject, 4, nullptr, _t1);
}

// SIGNAL 5
void SmithTool::ElementToolbar::addShuntResistor(double _t1)
{
    QMetaObject::activate<void>(this, &staticMetaObject, 5, nullptr, _t1);
}

// SIGNAL 6
void SmithTool::ElementToolbar::selectPointForElement(ComponentType _t1, ConnectionType _t2)
{
    QMetaObject::activate<void>(this, &staticMetaObject, 6, nullptr, _t1, _t2);
}

// SIGNAL 7
void SmithTool::ElementToolbar::clearAllElements()
{
    QMetaObject::activate(this, &staticMetaObject, 7, nullptr);
}

// SIGNAL 8
void SmithTool::ElementToolbar::undoLastElement()
{
    QMetaObject::activate(this, &staticMetaObject, 8, nullptr);
}
QT_WARNING_POP
