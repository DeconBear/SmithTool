/****************************************************************************
** Meta object code from reading C++ file 'smithchartwidget.h'
**
** Created by: The Qt Meta Object Compiler version 69 (Qt 6.10.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../src/ui/smithchartwidget.h"
#include <QtCore/qmetatype.h>

#include <QtCore/qtmochelpers.h>

#include <memory>


#include <QtCore/qxptype_traits.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'smithchartwidget.h' doesn't include <QObject>."
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
struct qt_meta_tag_ZN9SmithTool16SmithChartWidgetE_t {};
} // unnamed namespace

template <> constexpr inline auto SmithTool::SmithChartWidget::qt_create_metaobjectdata<qt_meta_tag_ZN9SmithTool16SmithChartWidgetE_t>()
{
    namespace QMC = QtMocConstants;
    QtMocHelpers::StringRefStorage qt_stringData {
        "SmithTool::SmithChartWidget",
        "pointClicked",
        "",
        "std::complex<double>",
        "gamma",
        "z",
        "pointHovered",
        "componentValuesCalculated",
        "freq",
        "r",
        "l",
        "c",
        "targetPointSelected",
        "ComponentType",
        "type",
        "ConnectionType",
        "conn",
        "elementValueDragged",
        "segmentIndex",
        "newValue",
        "dragEditStarted",
        "dragEditEnded",
        "resetViewRequested",
        "deleteElementRequested",
        "editElementRequested"
    };

    QtMocHelpers::UintData qt_methods {
        // Signal 'pointClicked'
        QtMocHelpers::SignalData<void(std::complex<double>, std::complex<double>)>(1, 2, QMC::AccessPublic, QMetaType::Void, {{
            { 0x80000000 | 3, 4 }, { 0x80000000 | 3, 5 },
        }}),
        // Signal 'pointHovered'
        QtMocHelpers::SignalData<void(std::complex<double>, std::complex<double>)>(6, 2, QMC::AccessPublic, QMetaType::Void, {{
            { 0x80000000 | 3, 4 }, { 0x80000000 | 3, 5 },
        }}),
        // Signal 'componentValuesCalculated'
        QtMocHelpers::SignalData<void(double, double, double, double)>(7, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::Double, 8 }, { QMetaType::Double, 9 }, { QMetaType::Double, 10 }, { QMetaType::Double, 11 },
        }}),
        // Signal 'targetPointSelected'
        QtMocHelpers::SignalData<void(std::complex<double>, std::complex<double>, ComponentType, ConnectionType)>(12, 2, QMC::AccessPublic, QMetaType::Void, {{
            { 0x80000000 | 3, 4 }, { 0x80000000 | 3, 5 }, { 0x80000000 | 13, 14 }, { 0x80000000 | 15, 16 },
        }}),
        // Signal 'elementValueDragged'
        QtMocHelpers::SignalData<void(int, double)>(17, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::Int, 18 }, { QMetaType::Double, 19 },
        }}),
        // Signal 'dragEditStarted'
        QtMocHelpers::SignalData<void(int)>(20, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::Int, 18 },
        }}),
        // Signal 'dragEditEnded'
        QtMocHelpers::SignalData<void()>(21, 2, QMC::AccessPublic, QMetaType::Void),
        // Signal 'resetViewRequested'
        QtMocHelpers::SignalData<void()>(22, 2, QMC::AccessPublic, QMetaType::Void),
        // Signal 'deleteElementRequested'
        QtMocHelpers::SignalData<void(int)>(23, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::Int, 18 },
        }}),
        // Signal 'editElementRequested'
        QtMocHelpers::SignalData<void(int)>(24, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::Int, 18 },
        }}),
    };
    QtMocHelpers::UintData qt_properties {
    };
    QtMocHelpers::UintData qt_enums {
    };
    return QtMocHelpers::metaObjectData<SmithChartWidget, qt_meta_tag_ZN9SmithTool16SmithChartWidgetE_t>(QMC::MetaObjectFlag{}, qt_stringData,
            qt_methods, qt_properties, qt_enums);
}
Q_CONSTINIT const QMetaObject SmithTool::SmithChartWidget::staticMetaObject = { {
    QMetaObject::SuperData::link<QWidget::staticMetaObject>(),
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN9SmithTool16SmithChartWidgetE_t>.stringdata,
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN9SmithTool16SmithChartWidgetE_t>.data,
    qt_static_metacall,
    nullptr,
    qt_staticMetaObjectRelocatingContent<qt_meta_tag_ZN9SmithTool16SmithChartWidgetE_t>.metaTypes,
    nullptr
} };

void SmithTool::SmithChartWidget::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    auto *_t = static_cast<SmithChartWidget *>(_o);
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: _t->pointClicked((*reinterpret_cast<std::add_pointer_t<std::complex<double>>>(_a[1])),(*reinterpret_cast<std::add_pointer_t<std::complex<double>>>(_a[2]))); break;
        case 1: _t->pointHovered((*reinterpret_cast<std::add_pointer_t<std::complex<double>>>(_a[1])),(*reinterpret_cast<std::add_pointer_t<std::complex<double>>>(_a[2]))); break;
        case 2: _t->componentValuesCalculated((*reinterpret_cast<std::add_pointer_t<double>>(_a[1])),(*reinterpret_cast<std::add_pointer_t<double>>(_a[2])),(*reinterpret_cast<std::add_pointer_t<double>>(_a[3])),(*reinterpret_cast<std::add_pointer_t<double>>(_a[4]))); break;
        case 3: _t->targetPointSelected((*reinterpret_cast<std::add_pointer_t<std::complex<double>>>(_a[1])),(*reinterpret_cast<std::add_pointer_t<std::complex<double>>>(_a[2])),(*reinterpret_cast<std::add_pointer_t<ComponentType>>(_a[3])),(*reinterpret_cast<std::add_pointer_t<ConnectionType>>(_a[4]))); break;
        case 4: _t->elementValueDragged((*reinterpret_cast<std::add_pointer_t<int>>(_a[1])),(*reinterpret_cast<std::add_pointer_t<double>>(_a[2]))); break;
        case 5: _t->dragEditStarted((*reinterpret_cast<std::add_pointer_t<int>>(_a[1]))); break;
        case 6: _t->dragEditEnded(); break;
        case 7: _t->resetViewRequested(); break;
        case 8: _t->deleteElementRequested((*reinterpret_cast<std::add_pointer_t<int>>(_a[1]))); break;
        case 9: _t->editElementRequested((*reinterpret_cast<std::add_pointer_t<int>>(_a[1]))); break;
        default: ;
        }
    }
    if (_c == QMetaObject::IndexOfMethod) {
        if (QtMocHelpers::indexOfMethod<void (SmithChartWidget::*)(std::complex<double> , std::complex<double> )>(_a, &SmithChartWidget::pointClicked, 0))
            return;
        if (QtMocHelpers::indexOfMethod<void (SmithChartWidget::*)(std::complex<double> , std::complex<double> )>(_a, &SmithChartWidget::pointHovered, 1))
            return;
        if (QtMocHelpers::indexOfMethod<void (SmithChartWidget::*)(double , double , double , double )>(_a, &SmithChartWidget::componentValuesCalculated, 2))
            return;
        if (QtMocHelpers::indexOfMethod<void (SmithChartWidget::*)(std::complex<double> , std::complex<double> , ComponentType , ConnectionType )>(_a, &SmithChartWidget::targetPointSelected, 3))
            return;
        if (QtMocHelpers::indexOfMethod<void (SmithChartWidget::*)(int , double )>(_a, &SmithChartWidget::elementValueDragged, 4))
            return;
        if (QtMocHelpers::indexOfMethod<void (SmithChartWidget::*)(int )>(_a, &SmithChartWidget::dragEditStarted, 5))
            return;
        if (QtMocHelpers::indexOfMethod<void (SmithChartWidget::*)()>(_a, &SmithChartWidget::dragEditEnded, 6))
            return;
        if (QtMocHelpers::indexOfMethod<void (SmithChartWidget::*)()>(_a, &SmithChartWidget::resetViewRequested, 7))
            return;
        if (QtMocHelpers::indexOfMethod<void (SmithChartWidget::*)(int )>(_a, &SmithChartWidget::deleteElementRequested, 8))
            return;
        if (QtMocHelpers::indexOfMethod<void (SmithChartWidget::*)(int )>(_a, &SmithChartWidget::editElementRequested, 9))
            return;
    }
}

const QMetaObject *SmithTool::SmithChartWidget::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *SmithTool::SmithChartWidget::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_staticMetaObjectStaticContent<qt_meta_tag_ZN9SmithTool16SmithChartWidgetE_t>.strings))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int SmithTool::SmithChartWidget::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 10)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 10;
    }
    if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 10)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 10;
    }
    return _id;
}

// SIGNAL 0
void SmithTool::SmithChartWidget::pointClicked(std::complex<double> _t1, std::complex<double> _t2)
{
    QMetaObject::activate<void>(this, &staticMetaObject, 0, nullptr, _t1, _t2);
}

// SIGNAL 1
void SmithTool::SmithChartWidget::pointHovered(std::complex<double> _t1, std::complex<double> _t2)
{
    QMetaObject::activate<void>(this, &staticMetaObject, 1, nullptr, _t1, _t2);
}

// SIGNAL 2
void SmithTool::SmithChartWidget::componentValuesCalculated(double _t1, double _t2, double _t3, double _t4)
{
    QMetaObject::activate<void>(this, &staticMetaObject, 2, nullptr, _t1, _t2, _t3, _t4);
}

// SIGNAL 3
void SmithTool::SmithChartWidget::targetPointSelected(std::complex<double> _t1, std::complex<double> _t2, ComponentType _t3, ConnectionType _t4)
{
    QMetaObject::activate<void>(this, &staticMetaObject, 3, nullptr, _t1, _t2, _t3, _t4);
}

// SIGNAL 4
void SmithTool::SmithChartWidget::elementValueDragged(int _t1, double _t2)
{
    QMetaObject::activate<void>(this, &staticMetaObject, 4, nullptr, _t1, _t2);
}

// SIGNAL 5
void SmithTool::SmithChartWidget::dragEditStarted(int _t1)
{
    QMetaObject::activate<void>(this, &staticMetaObject, 5, nullptr, _t1);
}

// SIGNAL 6
void SmithTool::SmithChartWidget::dragEditEnded()
{
    QMetaObject::activate(this, &staticMetaObject, 6, nullptr);
}

// SIGNAL 7
void SmithTool::SmithChartWidget::resetViewRequested()
{
    QMetaObject::activate(this, &staticMetaObject, 7, nullptr);
}

// SIGNAL 8
void SmithTool::SmithChartWidget::deleteElementRequested(int _t1)
{
    QMetaObject::activate<void>(this, &staticMetaObject, 8, nullptr, _t1);
}

// SIGNAL 9
void SmithTool::SmithChartWidget::editElementRequested(int _t1)
{
    QMetaObject::activate<void>(this, &staticMetaObject, 9, nullptr, _t1);
}
QT_WARNING_POP
