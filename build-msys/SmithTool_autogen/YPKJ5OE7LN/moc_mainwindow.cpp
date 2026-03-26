/****************************************************************************
** Meta object code from reading C++ file 'mainwindow.h'
**
** Created by: The Qt Meta Object Compiler version 69 (Qt 6.10.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../src/ui/mainwindow.h"
#include <QtGui/qtextcursor.h>
#include <QtCore/qmetatype.h>

#include <QtCore/qtmochelpers.h>

#include <memory>


#include <QtCore/qxptype_traits.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mainwindow.h' doesn't include <QObject>."
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
struct qt_meta_tag_ZN9SmithTool10MainWindowE_t {};
} // unnamed namespace

template <> constexpr inline auto SmithTool::MainWindow::qt_create_metaobjectdata<qt_meta_tag_ZN9SmithTool10MainWindowE_t>()
{
    namespace QMC = QtMocConstants;
    QtMocHelpers::StringRefStorage qt_stringData {
        "SmithTool::MainWindow",
        "onOpenFile",
        "",
        "onSaveFile",
        "onExportImage",
        "onAbout",
        "onPointClicked",
        "std::complex<double>",
        "gamma",
        "z",
        "onFrequencyChanged",
        "freq",
        "onZ0Changed",
        "z0",
        "onToggleAdmittance",
        "show",
        "onToggleVSWR",
        "onToggleLabels",
        "onToggleQCircles",
        "onConfigureQCircles",
        "onAddSeriesR",
        "onAddSeriesL",
        "onAddSeriesC",
        "onAddShuntR",
        "onAddShuntL",
        "onAddShuntC",
        "onRemoveLastElement",
        "onClearElements",
        "onSourceImpedanceChanged",
        "zs",
        "onLoadImpedanceChanged",
        "zl",
        "onOpenMatchingWizard",
        "onApplyMatchingSolution",
        "MatchingSolution",
        "solution",
        "onTargetPointSelected",
        "ComponentType",
        "type",
        "ConnectionType",
        "conn",
        "onElementValueDragged",
        "segmentIndex",
        "newValue",
        "onDragEditStarted",
        "onDragEditEnded",
        "onCircuitElementDoubleClicked",
        "index",
        "onDeleteElement",
        "onExportSpice"
    };

    QtMocHelpers::UintData qt_methods {
        // Slot 'onOpenFile'
        QtMocHelpers::SlotData<void()>(1, 2, QMC::AccessPrivate, QMetaType::Void),
        // Slot 'onSaveFile'
        QtMocHelpers::SlotData<void()>(3, 2, QMC::AccessPrivate, QMetaType::Void),
        // Slot 'onExportImage'
        QtMocHelpers::SlotData<void()>(4, 2, QMC::AccessPrivate, QMetaType::Void),
        // Slot 'onAbout'
        QtMocHelpers::SlotData<void()>(5, 2, QMC::AccessPrivate, QMetaType::Void),
        // Slot 'onPointClicked'
        QtMocHelpers::SlotData<void(std::complex<double>, std::complex<double>)>(6, 2, QMC::AccessPrivate, QMetaType::Void, {{
            { 0x80000000 | 7, 8 }, { 0x80000000 | 7, 9 },
        }}),
        // Slot 'onFrequencyChanged'
        QtMocHelpers::SlotData<void(double)>(10, 2, QMC::AccessPrivate, QMetaType::Void, {{
            { QMetaType::Double, 11 },
        }}),
        // Slot 'onZ0Changed'
        QtMocHelpers::SlotData<void(double)>(12, 2, QMC::AccessPrivate, QMetaType::Void, {{
            { QMetaType::Double, 13 },
        }}),
        // Slot 'onToggleAdmittance'
        QtMocHelpers::SlotData<void(bool)>(14, 2, QMC::AccessPrivate, QMetaType::Void, {{
            { QMetaType::Bool, 15 },
        }}),
        // Slot 'onToggleVSWR'
        QtMocHelpers::SlotData<void(bool)>(16, 2, QMC::AccessPrivate, QMetaType::Void, {{
            { QMetaType::Bool, 15 },
        }}),
        // Slot 'onToggleLabels'
        QtMocHelpers::SlotData<void(bool)>(17, 2, QMC::AccessPrivate, QMetaType::Void, {{
            { QMetaType::Bool, 15 },
        }}),
        // Slot 'onToggleQCircles'
        QtMocHelpers::SlotData<void(bool)>(18, 2, QMC::AccessPrivate, QMetaType::Void, {{
            { QMetaType::Bool, 15 },
        }}),
        // Slot 'onConfigureQCircles'
        QtMocHelpers::SlotData<void()>(19, 2, QMC::AccessPrivate, QMetaType::Void),
        // Slot 'onAddSeriesR'
        QtMocHelpers::SlotData<void()>(20, 2, QMC::AccessPrivate, QMetaType::Void),
        // Slot 'onAddSeriesL'
        QtMocHelpers::SlotData<void()>(21, 2, QMC::AccessPrivate, QMetaType::Void),
        // Slot 'onAddSeriesC'
        QtMocHelpers::SlotData<void()>(22, 2, QMC::AccessPrivate, QMetaType::Void),
        // Slot 'onAddShuntR'
        QtMocHelpers::SlotData<void()>(23, 2, QMC::AccessPrivate, QMetaType::Void),
        // Slot 'onAddShuntL'
        QtMocHelpers::SlotData<void()>(24, 2, QMC::AccessPrivate, QMetaType::Void),
        // Slot 'onAddShuntC'
        QtMocHelpers::SlotData<void()>(25, 2, QMC::AccessPrivate, QMetaType::Void),
        // Slot 'onRemoveLastElement'
        QtMocHelpers::SlotData<void()>(26, 2, QMC::AccessPrivate, QMetaType::Void),
        // Slot 'onClearElements'
        QtMocHelpers::SlotData<void()>(27, 2, QMC::AccessPrivate, QMetaType::Void),
        // Slot 'onSourceImpedanceChanged'
        QtMocHelpers::SlotData<void(std::complex<double>)>(28, 2, QMC::AccessPrivate, QMetaType::Void, {{
            { 0x80000000 | 7, 29 },
        }}),
        // Slot 'onLoadImpedanceChanged'
        QtMocHelpers::SlotData<void(std::complex<double>)>(30, 2, QMC::AccessPrivate, QMetaType::Void, {{
            { 0x80000000 | 7, 31 },
        }}),
        // Slot 'onOpenMatchingWizard'
        QtMocHelpers::SlotData<void()>(32, 2, QMC::AccessPrivate, QMetaType::Void),
        // Slot 'onApplyMatchingSolution'
        QtMocHelpers::SlotData<void(const MatchingSolution &)>(33, 2, QMC::AccessPrivate, QMetaType::Void, {{
            { 0x80000000 | 34, 35 },
        }}),
        // Slot 'onTargetPointSelected'
        QtMocHelpers::SlotData<void(std::complex<double>, std::complex<double>, ComponentType, ConnectionType)>(36, 2, QMC::AccessPrivate, QMetaType::Void, {{
            { 0x80000000 | 7, 8 }, { 0x80000000 | 7, 9 }, { 0x80000000 | 37, 38 }, { 0x80000000 | 39, 40 },
        }}),
        // Slot 'onElementValueDragged'
        QtMocHelpers::SlotData<void(int, double)>(41, 2, QMC::AccessPrivate, QMetaType::Void, {{
            { QMetaType::Int, 42 }, { QMetaType::Double, 43 },
        }}),
        // Slot 'onDragEditStarted'
        QtMocHelpers::SlotData<void(int)>(44, 2, QMC::AccessPrivate, QMetaType::Void, {{
            { QMetaType::Int, 42 },
        }}),
        // Slot 'onDragEditEnded'
        QtMocHelpers::SlotData<void()>(45, 2, QMC::AccessPrivate, QMetaType::Void),
        // Slot 'onCircuitElementDoubleClicked'
        QtMocHelpers::SlotData<void(int)>(46, 2, QMC::AccessPrivate, QMetaType::Void, {{
            { QMetaType::Int, 47 },
        }}),
        // Slot 'onDeleteElement'
        QtMocHelpers::SlotData<void(int)>(48, 2, QMC::AccessPrivate, QMetaType::Void, {{
            { QMetaType::Int, 47 },
        }}),
        // Slot 'onExportSpice'
        QtMocHelpers::SlotData<void()>(49, 2, QMC::AccessPrivate, QMetaType::Void),
    };
    QtMocHelpers::UintData qt_properties {
    };
    QtMocHelpers::UintData qt_enums {
    };
    return QtMocHelpers::metaObjectData<MainWindow, qt_meta_tag_ZN9SmithTool10MainWindowE_t>(QMC::MetaObjectFlag{}, qt_stringData,
            qt_methods, qt_properties, qt_enums);
}
Q_CONSTINIT const QMetaObject SmithTool::MainWindow::staticMetaObject = { {
    QMetaObject::SuperData::link<QMainWindow::staticMetaObject>(),
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN9SmithTool10MainWindowE_t>.stringdata,
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN9SmithTool10MainWindowE_t>.data,
    qt_static_metacall,
    nullptr,
    qt_staticMetaObjectRelocatingContent<qt_meta_tag_ZN9SmithTool10MainWindowE_t>.metaTypes,
    nullptr
} };

void SmithTool::MainWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    auto *_t = static_cast<MainWindow *>(_o);
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: _t->onOpenFile(); break;
        case 1: _t->onSaveFile(); break;
        case 2: _t->onExportImage(); break;
        case 3: _t->onAbout(); break;
        case 4: _t->onPointClicked((*reinterpret_cast<std::add_pointer_t<std::complex<double>>>(_a[1])),(*reinterpret_cast<std::add_pointer_t<std::complex<double>>>(_a[2]))); break;
        case 5: _t->onFrequencyChanged((*reinterpret_cast<std::add_pointer_t<double>>(_a[1]))); break;
        case 6: _t->onZ0Changed((*reinterpret_cast<std::add_pointer_t<double>>(_a[1]))); break;
        case 7: _t->onToggleAdmittance((*reinterpret_cast<std::add_pointer_t<bool>>(_a[1]))); break;
        case 8: _t->onToggleVSWR((*reinterpret_cast<std::add_pointer_t<bool>>(_a[1]))); break;
        case 9: _t->onToggleLabels((*reinterpret_cast<std::add_pointer_t<bool>>(_a[1]))); break;
        case 10: _t->onToggleQCircles((*reinterpret_cast<std::add_pointer_t<bool>>(_a[1]))); break;
        case 11: _t->onConfigureQCircles(); break;
        case 12: _t->onAddSeriesR(); break;
        case 13: _t->onAddSeriesL(); break;
        case 14: _t->onAddSeriesC(); break;
        case 15: _t->onAddShuntR(); break;
        case 16: _t->onAddShuntL(); break;
        case 17: _t->onAddShuntC(); break;
        case 18: _t->onRemoveLastElement(); break;
        case 19: _t->onClearElements(); break;
        case 20: _t->onSourceImpedanceChanged((*reinterpret_cast<std::add_pointer_t<std::complex<double>>>(_a[1]))); break;
        case 21: _t->onLoadImpedanceChanged((*reinterpret_cast<std::add_pointer_t<std::complex<double>>>(_a[1]))); break;
        case 22: _t->onOpenMatchingWizard(); break;
        case 23: _t->onApplyMatchingSolution((*reinterpret_cast<std::add_pointer_t<MatchingSolution>>(_a[1]))); break;
        case 24: _t->onTargetPointSelected((*reinterpret_cast<std::add_pointer_t<std::complex<double>>>(_a[1])),(*reinterpret_cast<std::add_pointer_t<std::complex<double>>>(_a[2])),(*reinterpret_cast<std::add_pointer_t<ComponentType>>(_a[3])),(*reinterpret_cast<std::add_pointer_t<ConnectionType>>(_a[4]))); break;
        case 25: _t->onElementValueDragged((*reinterpret_cast<std::add_pointer_t<int>>(_a[1])),(*reinterpret_cast<std::add_pointer_t<double>>(_a[2]))); break;
        case 26: _t->onDragEditStarted((*reinterpret_cast<std::add_pointer_t<int>>(_a[1]))); break;
        case 27: _t->onDragEditEnded(); break;
        case 28: _t->onCircuitElementDoubleClicked((*reinterpret_cast<std::add_pointer_t<int>>(_a[1]))); break;
        case 29: _t->onDeleteElement((*reinterpret_cast<std::add_pointer_t<int>>(_a[1]))); break;
        case 30: _t->onExportSpice(); break;
        default: ;
        }
    }
}

const QMetaObject *SmithTool::MainWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *SmithTool::MainWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_staticMetaObjectStaticContent<qt_meta_tag_ZN9SmithTool10MainWindowE_t>.strings))
        return static_cast<void*>(this);
    return QMainWindow::qt_metacast(_clname);
}

int SmithTool::MainWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 31)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 31;
    }
    if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 31)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 31;
    }
    return _id;
}
QT_WARNING_POP
