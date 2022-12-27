/****************************************************************************
** Meta object code from reading C++ file 'widget.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.2.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "Headers/widget.h"
#include <QtGui/qtextcursor.h>
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'widget.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.2.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_Widget_t {
    const uint offsetsAndSize[36];
    char stringdata0[334];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(offsetof(qt_meta_stringdata_Widget_t, stringdata0) + ofs), len 
static const qt_meta_stringdata_Widget_t qt_meta_stringdata_Widget = {
    {
QT_MOC_LITERAL(0, 6), // "Widget"
QT_MOC_LITERAL(7, 11), // "updateScore"
QT_MOC_LITERAL(19, 0), // ""
QT_MOC_LITERAL(20, 11), // "createLevel"
QT_MOC_LITERAL(32, 22), // "on_startButton_clicked"
QT_MOC_LITERAL(55, 21), // "on_quitButton_clicked"
QT_MOC_LITERAL(77, 25), // "on_settingsButton_clicked"
QT_MOC_LITERAL(103, 21), // "on_pushButton_clicked"
QT_MOC_LITERAL(125, 26), // "on_checkSound_stateChanged"
QT_MOC_LITERAL(152, 4), // "arg1"
QT_MOC_LITERAL(157, 17), // "on_rbEasy_clicked"
QT_MOC_LITERAL(175, 17), // "on_rbHard_clicked"
QT_MOC_LITERAL(193, 25), // "on_rangListButton_clicked"
QT_MOC_LITERAL(219, 29), // "on_pushButtonMainMenu_clicked"
QT_MOC_LITERAL(249, 21), // "on_helpButton_clicked"
QT_MOC_LITERAL(271, 21), // "on_buttonBox_accepted"
QT_MOC_LITERAL(293, 21), // "on_buttonBox_rejected"
QT_MOC_LITERAL(315, 18) // "on_Give_up_clicked"

    },
    "Widget\0updateScore\0\0createLevel\0"
    "on_startButton_clicked\0on_quitButton_clicked\0"
    "on_settingsButton_clicked\0"
    "on_pushButton_clicked\0on_checkSound_stateChanged\0"
    "arg1\0on_rbEasy_clicked\0on_rbHard_clicked\0"
    "on_rangListButton_clicked\0"
    "on_pushButtonMainMenu_clicked\0"
    "on_helpButton_clicked\0on_buttonBox_accepted\0"
    "on_buttonBox_rejected\0on_Give_up_clicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Widget[] = {

 // content:
      10,       // revision
       0,       // classname
       0,    0, // classinfo
      15,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       1,    0,  104,    2, 0x08,    1 /* Private */,
       3,    0,  105,    2, 0x08,    2 /* Private */,
       4,    0,  106,    2, 0x08,    3 /* Private */,
       5,    0,  107,    2, 0x08,    4 /* Private */,
       6,    0,  108,    2, 0x08,    5 /* Private */,
       7,    0,  109,    2, 0x08,    6 /* Private */,
       8,    1,  110,    2, 0x08,    7 /* Private */,
      10,    0,  113,    2, 0x08,    9 /* Private */,
      11,    0,  114,    2, 0x08,   10 /* Private */,
      12,    0,  115,    2, 0x08,   11 /* Private */,
      13,    0,  116,    2, 0x08,   12 /* Private */,
      14,    0,  117,    2, 0x08,   13 /* Private */,
      15,    0,  118,    2, 0x08,   14 /* Private */,
      16,    0,  119,    2, 0x08,   15 /* Private */,
      17,    0,  120,    2, 0x08,   16 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,    9,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void Widget::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<Widget *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->updateScore(); break;
        case 1: _t->createLevel(); break;
        case 2: _t->on_startButton_clicked(); break;
        case 3: _t->on_quitButton_clicked(); break;
        case 4: _t->on_settingsButton_clicked(); break;
        case 5: _t->on_pushButton_clicked(); break;
        case 6: _t->on_checkSound_stateChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 7: _t->on_rbEasy_clicked(); break;
        case 8: _t->on_rbHard_clicked(); break;
        case 9: _t->on_rangListButton_clicked(); break;
        case 10: _t->on_pushButtonMainMenu_clicked(); break;
        case 11: _t->on_helpButton_clicked(); break;
        case 12: _t->on_buttonBox_accepted(); break;
        case 13: _t->on_buttonBox_rejected(); break;
        case 14: _t->on_Give_up_clicked(); break;
        default: ;
        }
    }
}

const QMetaObject Widget::staticMetaObject = { {
    QMetaObject::SuperData::link<QWidget::staticMetaObject>(),
    qt_meta_stringdata_Widget.offsetsAndSize,
    qt_meta_data_Widget,
    qt_static_metacall,
    nullptr,
qt_incomplete_metaTypeArray<qt_meta_stringdata_Widget_t
, QtPrivate::TypeAndForceComplete<Widget, std::true_type>
, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>


>,
    nullptr
} };


const QMetaObject *Widget::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Widget::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_Widget.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int Widget::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 15)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 15;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 15)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 15;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
