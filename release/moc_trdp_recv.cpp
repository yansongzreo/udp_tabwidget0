/****************************************************************************
** Meta object code from reading C++ file 'trdp_recv.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.9.9)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../trdp_recv.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'trdp_recv.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.9.9. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_trdp_recv_t {
    QByteArrayData data[10];
    char stringdata0[136];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_trdp_recv_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_trdp_recv_t qt_meta_stringdata_trdp_recv = {
    {
QT_MOC_LITERAL(0, 0, 9), // "trdp_recv"
QT_MOC_LITERAL(1, 10, 15), // "connUpperSignal"
QT_MOC_LITERAL(2, 26, 0), // ""
QT_MOC_LITERAL(3, 27, 5), // "strip"
QT_MOC_LITERAL(4, 33, 7), // "excelid"
QT_MOC_LITERAL(5, 41, 5), // "errid"
QT_MOC_LITERAL(6, 47, 22), // "refreshTabwidgetSignal"
QT_MOC_LITERAL(7, 70, 20), // "heartbeatErrorSignal"
QT_MOC_LITERAL(8, 91, 20), // "doHeartbeatcheckSlot"
QT_MOC_LITERAL(9, 112, 23) // "processPendingDatagrams"

    },
    "trdp_recv\0connUpperSignal\0\0strip\0"
    "excelid\0errid\0refreshTabwidgetSignal\0"
    "heartbeatErrorSignal\0doHeartbeatcheckSlot\0"
    "processPendingDatagrams"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_trdp_recv[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       5,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       3,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    3,   39,    2, 0x06 /* Public */,
       6,    2,   46,    2, 0x06 /* Public */,
       7,    2,   51,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       8,    0,   56,    2, 0x08 /* Private */,
       9,    0,   57,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, QMetaType::QString, QMetaType::Int, QMetaType::Int,    3,    4,    5,
    QMetaType::Void, QMetaType::QStringList, QMetaType::Int,    2,    2,
    QMetaType::Void, QMetaType::Int, QMetaType::Int,    2,    2,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void trdp_recv::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        trdp_recv *_t = static_cast<trdp_recv *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->connUpperSignal((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3]))); break;
        case 1: _t->refreshTabwidgetSignal((*reinterpret_cast< QStringList(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 2: _t->heartbeatErrorSignal((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 3: _t->doHeartbeatcheckSlot(); break;
        case 4: _t->processPendingDatagrams(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            typedef void (trdp_recv::*_t)(QString , int , int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&trdp_recv::connUpperSignal)) {
                *result = 0;
                return;
            }
        }
        {
            typedef void (trdp_recv::*_t)(QStringList , int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&trdp_recv::refreshTabwidgetSignal)) {
                *result = 1;
                return;
            }
        }
        {
            typedef void (trdp_recv::*_t)(int , int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&trdp_recv::heartbeatErrorSignal)) {
                *result = 2;
                return;
            }
        }
    }
}

const QMetaObject trdp_recv::staticMetaObject = {
    { &QThread::staticMetaObject, qt_meta_stringdata_trdp_recv.data,
      qt_meta_data_trdp_recv,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *trdp_recv::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *trdp_recv::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_trdp_recv.stringdata0))
        return static_cast<void*>(this);
    return QThread::qt_metacast(_clname);
}

int trdp_recv::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QThread::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 5)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 5;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 5)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 5;
    }
    return _id;
}

// SIGNAL 0
void trdp_recv::connUpperSignal(QString _t1, int _t2, int _t3)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void trdp_recv::refreshTabwidgetSignal(QStringList _t1, int _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void trdp_recv::heartbeatErrorSignal(int _t1, int _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
