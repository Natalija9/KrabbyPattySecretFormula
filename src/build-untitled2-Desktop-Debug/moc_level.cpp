/****************************************************************************
** Meta object code from reading C++ file 'level.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.2.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../krabbyPatty/level.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'level.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.2.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_Level_t {
    const uint offsetsAndSize[16];
    char stringdata0[73];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(offsetof(qt_meta_stringdata_Level_t, stringdata0) + ofs), len 
static const qt_meta_stringdata_Level_t qt_meta_stringdata_Level = {
    {
QT_MOC_LITERAL(0, 5), // "Level"
QT_MOC_LITERAL(6, 8), // "endLevel"
QT_MOC_LITERAL(15, 0), // ""
QT_MOC_LITERAL(16, 13), // "increaseScore"
QT_MOC_LITERAL(30, 12), // "increaseLife"
QT_MOC_LITERAL(43, 13), // "decreaseScore"
QT_MOC_LITERAL(57, 5), // "death"
QT_MOC_LITERAL(63, 9) // "outOfTime"

    },
    "Level\0endLevel\0\0increaseScore\0"
    "increaseLife\0decreaseScore\0death\0"
    "outOfTime"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Level[] = {

 // content:
      10,       // revision
       0,       // classname
       0,    0, // classinfo
       6,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags, initial metatype offsets
       1,    0,   50,    2, 0x06,    1 /* Public */,

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       3,    0,   51,    2, 0x0a,    2 /* Public */,
       4,    0,   52,    2, 0x0a,    3 /* Public */,
       5,    0,   53,    2, 0x0a,    4 /* Public */,
       6,    0,   54,    2, 0x0a,    5 /* Public */,
       7,    0,   55,    2, 0x0a,    6 /* Public */,

 // signals: parameters
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void Level::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<Level *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->endLevel(); break;
        case 1: _t->increaseScore(); break;
        case 2: _t->increaseLife(); break;
        case 3: _t->decreaseScore(); break;
        case 4: _t->death(); break;
        case 5: _t->outOfTime(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (Level::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Level::endLevel)) {
                *result = 0;
                return;
            }
        }
    }
    (void)_a;
}

const QMetaObject Level::staticMetaObject = { {
    QMetaObject::SuperData::link<QGraphicsView::staticMetaObject>(),
    qt_meta_stringdata_Level.offsetsAndSize,
    qt_meta_data_Level,
    qt_static_metacall,
    nullptr,
qt_incomplete_metaTypeArray<qt_meta_stringdata_Level_t
, QtPrivate::TypeAndForceComplete<Level, std::true_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>
, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>


>,
    nullptr
} };


const QMetaObject *Level::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Level::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_Level.stringdata0))
        return static_cast<void*>(this);
    return QGraphicsView::qt_metacast(_clname);
}

int Level::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QGraphicsView::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 6)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 6;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 6)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 6;
    }
    return _id;
}

// SIGNAL 0
void Level::endLevel()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
