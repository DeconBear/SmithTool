/****************************************************************************
** Meta object code from reading C++ file 'impedanceinputpanel.h'
**
** Created by: The Qt Meta Object Compiler version 69 (Qt 6.10.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../src/ui/impedanceinputpanel.h"
#include <QtGui/qtextcursor.h>
#include <QtCore/qmetatype.h>

#include <QtCore/qtmochelpers.h>

#include <memory>


#include <QtCore/qxptype_traits.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'impedanceinputpanel.h' doesn't include <QObject>."
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
struct qt_meta_tag_ZN9SmithTool19ImpedanceInputPanelE_t {};
} // unnamed namespace

template <> constexpr inline auto SmithTool::ImpedanceInputPanel::qt_create_metaobjectdata<qt_meta_tag_ZN9SmithTool19ImpedanceInputPanelE_t>()
{
    namespace QMC = QtMocConstants;
    QtMocHelpers::StringRefStorage qt_stringData {
        "SmithTool::ImpedanceInputPanel",
        "sourceImpedanceChanged",
        "",
        "std::complex<double>",
        "zs",
        "loadImpedanceChanged",
        "zl",
        "z0Changed",
        "z0",
        "onSourceFormatChanged",
        "onLoadFormatChanged",
        "onSourceValueChanged",
        "onLoadValueChanged",
        "onZ0Changed"
    };

    QtMocHelpers::UintData qt_methods {
        // Signal 'sourceImpedanceChanged'
        QtMocHelpers::SignalData<void(std::complex<double>)>(1, 2, QMC::AccessPublic, QMetaType::Void, {{
            { 0x80000000 | 3, 4 },
        }}),
        // Signal 'loadImpedanceChanged'
        QtMocHelpers::SignalData<void(std::complex<double>)>(5, 2, QMC::AccessPublic, QMetaType::Void, {{
            { 0x80000000 | 3, 6 },
        }}),
        // Signal 'z0Changed'
        QtMocHelpers::SignalData<void(double)>(7, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::Double, 8 },
        }}),
        // Slot 'onSourceFormatChanged'
        QtMocHelpers::SlotData<void()>(9, 2, QMC::AccessPrivate, QMetaType::Void),
        // Slot 'onLoadFormatChanged'
        QtMocHelpers::SlotData<void()>(10, 2, QMC::AccessPrivate, QMetaType::Void),
        // Slot 'onSourceValueChanged'
        QtMocHelpers::SlotData<void()>(11, 2, QMC::AccessPrivate, QMetaType::Void),
        // Slot 'onLoadValueChanged'
        QtMocHelpers::SlotData<void()>(12, 2, QMC::AccessPrivate, QMetaType::Void),
        // Slot 'onZ0Changed'
        QtMocHelpers::SlotData<void()>(13, 2, QMC::AccessPrivate, QMetaType::Void),
    };
    QtMocHelpers::UintData qt_properties {
    };
    QtMocHelpers::UintData qt_enums {
    };
    return QtMocHelpers::metaObjectData<ImpedanceInputPanel, qt_meta_tag_ZN9SmithTool19ImpedanceInputPanelE_t>(QMC::MetaObjectFlag{}, qt_stringData,
            qt_methods, qt_properties, qt_enums);
}
Q_CONSTINIT const QMetaObject SmithTool::ImpedanceInputPanel::staticMetaObject = { {
    QMetaObject::SuperData::link<QWidget::staticMetaObject>(),
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN9SmithTool19ImpedanceInputPanelE_t>.stringdata,
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN9SmithTool19ImpedanceInputPanelE_t>.data,
    qt_static_metacall,
    nullptr,
    qt_staticMetaObjectRelocatingContent<qt_meta_tag_ZN9SmithTool19ImpedanceInputPanelE_t>.metaTypes,
    nullptr
} };

void SmithTool::ImpedanceInputPanel::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    auto *_t = static_cast<ImpedanceInputPanel *>(_o);
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: _t->sourceImpedanceChanged((*reinterpret_cast<std::add_pointer_t<std::complex<double>>>(_a[1]))); break;
        case 1: _t->loadImpedanceChanged((*reinterpret_cast<std::add_pointer_t<std::complex<double>>>(_a[1]))); break;
        case 2: _t->z0Changed((*reinterpret_cast<std::add_pointer_t<double>>(_a[1]))); break;
        case 3: _t->onSourceFormatChanged(); break;
        case 4: _t->onLoadFormatChanged(); break;
        case 5: _t->onSourceValueChanged(); break;
        case 6: _t->onLoadValueChanged(); break;
        case 7: _t->onZ0Changed(); break;
        default: ;
        }
    }
    if (_c == QMetaObject::IndexOfMethod) {
        if (QtMocHelpers::indexOfMethod<void (ImpedanceInputPanel::*)(std::complex<double> )>(_a, &ImpedanceInputPanel::sourceImpedanceChanged, 0))
            return;
        if (QtMocHelpers::indexOfMethod<void (ImpedanceInputPanel::*)(std::complex<double> )>(_a, &ImpedanceInputPanel::loadImpedanceChanged, 1))
            return;
        if (QtMocHelpers::indexOfMethod<void (ImpedanceInputPanel::*)(double )>(_a, &ImpedanceInputPanel::z0Changed, 2))
            return;
    }
}

const QMetaObject *SmithTool::ImpedanceInputPanel::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *SmithTool::ImpedanceInputPanel::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_staticMetaObjectStaticContent<qt_meta_tag_ZN9SmithTool19ImpedanceInputPanelE_t>.strings))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int SmithTool::ImpedanceInputPanel::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 8)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 8;
    }
    if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 8)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 8;
    }
    return _id;
}

// SIGNAL 0
void SmithTool::ImpedanceInputPanel::sourceImpedanceChanged(std::complex<double> _t1)
{
    QMetaObject::activate<void>(this, &staticMetaObject, 0, nullptr, _t1);
}

// SIGNAL 1
void SmithTool::ImpedanceInputPanel::loadImpedanceChanged(std::complex<double> _t1)
{
    QMetaObject::activate<void>(this, &staticMetaObject, 1, nullptr, _t1);
}

// SIGNAL 2
void SmithTool::ImpedanceInputPanel::z0Changed(double _t1)
{
    QMetaObject::activate<void>(this, &staticMetaObject, 2, nullptr, _t1);
}
QT_WARNING_POP
