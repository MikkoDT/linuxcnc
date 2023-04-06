/****************************************************************************
** Meta object code from reading C++ file 'mainwindow.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.15.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../../../../projects/qt_ruckig_gui/mainwindow.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mainwindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.15.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_MainWindow_t {
    QByteArrayData data[16];
    char stringdata0[417];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_MainWindow_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_MainWindow_t qt_meta_stringdata_MainWindow = {
    {
QT_MOC_LITERAL(0, 0, 10), // "MainWindow"
QT_MOC_LITERAL(1, 11, 6), // "thread"
QT_MOC_LITERAL(2, 18, 0), // ""
QT_MOC_LITERAL(3, 19, 25), // "on_pushButton_run_pressed"
QT_MOC_LITERAL(4, 45, 27), // "on_pushButton_pause_pressed"
QT_MOC_LITERAL(5, 73, 36), // "on_doubleSpinBox_tarpos_value..."
QT_MOC_LITERAL(6, 110, 4), // "arg1"
QT_MOC_LITERAL(7, 115, 32), // "on_doubleSpinBox_vm_valueChanged"
QT_MOC_LITERAL(8, 148, 31), // "on_doubleSpinBox_a_valueChanged"
QT_MOC_LITERAL(9, 180, 32), // "on_doubleSpinBox_ve_valueChanged"
QT_MOC_LITERAL(10, 213, 32), // "on_doubleSpinBox_jm_valueChanged"
QT_MOC_LITERAL(11, 246, 32), // "on_doubleSpinBox_vo_valueChanged"
QT_MOC_LITERAL(12, 279, 31), // "on_doubleSpinBox_s_valueChanged"
QT_MOC_LITERAL(13, 311, 33), // "on_doubleSpinBox_acs_valueCha..."
QT_MOC_LITERAL(14, 345, 33), // "on_doubleSpinBox_ace_valueCha..."
QT_MOC_LITERAL(15, 379, 37) // "on_pushButton_set_mempos_zero..."

    },
    "MainWindow\0thread\0\0on_pushButton_run_pressed\0"
    "on_pushButton_pause_pressed\0"
    "on_doubleSpinBox_tarpos_valueChanged\0"
    "arg1\0on_doubleSpinBox_vm_valueChanged\0"
    "on_doubleSpinBox_a_valueChanged\0"
    "on_doubleSpinBox_ve_valueChanged\0"
    "on_doubleSpinBox_jm_valueChanged\0"
    "on_doubleSpinBox_vo_valueChanged\0"
    "on_doubleSpinBox_s_valueChanged\0"
    "on_doubleSpinBox_acs_valueChanged\0"
    "on_doubleSpinBox_ace_valueChanged\0"
    "on_pushButton_set_mempos_zero_pressed"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MainWindow[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      13,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   79,    2, 0x08 /* Private */,
       3,    0,   80,    2, 0x08 /* Private */,
       4,    0,   81,    2, 0x08 /* Private */,
       5,    1,   82,    2, 0x08 /* Private */,
       7,    1,   85,    2, 0x08 /* Private */,
       8,    1,   88,    2, 0x08 /* Private */,
       9,    1,   91,    2, 0x08 /* Private */,
      10,    1,   94,    2, 0x08 /* Private */,
      11,    1,   97,    2, 0x08 /* Private */,
      12,    1,  100,    2, 0x08 /* Private */,
      13,    1,  103,    2, 0x08 /* Private */,
      14,    1,  106,    2, 0x08 /* Private */,
      15,    0,  109,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Double,    6,
    QMetaType::Void, QMetaType::Double,    6,
    QMetaType::Void, QMetaType::Double,    6,
    QMetaType::Void, QMetaType::Double,    6,
    QMetaType::Void, QMetaType::Double,    6,
    QMetaType::Void, QMetaType::Double,    6,
    QMetaType::Void, QMetaType::Double,    6,
    QMetaType::Void, QMetaType::Double,    6,
    QMetaType::Void, QMetaType::Double,    6,
    QMetaType::Void,

       0        // eod
};

void MainWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<MainWindow *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->thread(); break;
        case 1: _t->on_pushButton_run_pressed(); break;
        case 2: _t->on_pushButton_pause_pressed(); break;
        case 3: _t->on_doubleSpinBox_tarpos_valueChanged((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 4: _t->on_doubleSpinBox_vm_valueChanged((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 5: _t->on_doubleSpinBox_a_valueChanged((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 6: _t->on_doubleSpinBox_ve_valueChanged((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 7: _t->on_doubleSpinBox_jm_valueChanged((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 8: _t->on_doubleSpinBox_vo_valueChanged((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 9: _t->on_doubleSpinBox_s_valueChanged((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 10: _t->on_doubleSpinBox_acs_valueChanged((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 11: _t->on_doubleSpinBox_ace_valueChanged((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 12: _t->on_pushButton_set_mempos_zero_pressed(); break;
        default: ;
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject MainWindow::staticMetaObject = { {
    QMetaObject::SuperData::link<QMainWindow::staticMetaObject>(),
    qt_meta_stringdata_MainWindow.data,
    qt_meta_data_MainWindow,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *MainWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MainWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_MainWindow.stringdata0))
        return static_cast<void*>(this);
    return QMainWindow::qt_metacast(_clname);
}

int MainWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 13)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 13;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 13)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 13;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
