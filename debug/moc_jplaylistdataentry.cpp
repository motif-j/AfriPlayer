/****************************************************************************
** Meta object code from reading C++ file 'jplaylistdataentry.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.15.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../src/adapters/jplaylistdataentry.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#include <QtCore/QList>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'jplaylistdataentry.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.15.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_JPlaylistDataEntry_t {
    QByteArrayData data[9];
    char stringdata0[136];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_JPlaylistDataEntry_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_JPlaylistDataEntry_t qt_meta_stringdata_JPlaylistDataEntry = {
    {
QT_MOC_LITERAL(0, 0, 18), // "JPlaylistDataEntry"
QT_MOC_LITERAL(1, 19, 26), // "fetchHomePlaylistsFromRepo"
QT_MOC_LITERAL(2, 46, 0), // ""
QT_MOC_LITERAL(3, 47, 12), // "countChanged"
QT_MOC_LITERAL(4, 60, 17), // "loadHomePlaylists"
QT_MOC_LITERAL(5, 78, 26), // "handleHomePlaylistsFetched"
QT_MOC_LITERAL(6, 105, 17), // "QList<JPlaylist>*"
QT_MOC_LITERAL(7, 123, 6), // "result"
QT_MOC_LITERAL(8, 130, 5) // "count"

    },
    "JPlaylistDataEntry\0fetchHomePlaylistsFromRepo\0"
    "\0countChanged\0loadHomePlaylists\0"
    "handleHomePlaylistsFetched\0QList<JPlaylist>*\0"
    "result\0count"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_JPlaylistDataEntry[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       4,   14, // methods
       1,   40, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   34,    2, 0x06 /* Public */,
       3,    0,   35,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       4,    0,   36,    2, 0x0a /* Public */,
       5,    1,   37,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 6,    7,

 // properties: name, type, flags
       8, QMetaType::Int, 0x00495103,

 // properties: notify_signal_id
       1,

       0        // eod
};

void JPlaylistDataEntry::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<JPlaylistDataEntry *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->fetchHomePlaylistsFromRepo(); break;
        case 1: _t->countChanged(); break;
        case 2: _t->loadHomePlaylists(); break;
        case 3: _t->handleHomePlaylistsFetched((*reinterpret_cast< QList<JPlaylist>*(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (JPlaylistDataEntry::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&JPlaylistDataEntry::fetchHomePlaylistsFromRepo)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (JPlaylistDataEntry::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&JPlaylistDataEntry::countChanged)) {
                *result = 1;
                return;
            }
        }
    }
#ifndef QT_NO_PROPERTIES
    else if (_c == QMetaObject::ReadProperty) {
        auto *_t = static_cast<JPlaylistDataEntry *>(_o);
        Q_UNUSED(_t)
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast< int*>(_v) = _t->getCount(); break;
        default: break;
        }
    } else if (_c == QMetaObject::WriteProperty) {
        auto *_t = static_cast<JPlaylistDataEntry *>(_o);
        Q_UNUSED(_t)
        void *_v = _a[0];
        switch (_id) {
        case 0: _t->setCount(*reinterpret_cast< int*>(_v)); break;
        default: break;
        }
    } else if (_c == QMetaObject::ResetProperty) {
    }
#endif // QT_NO_PROPERTIES
}

QT_INIT_METAOBJECT const QMetaObject JPlaylistDataEntry::staticMetaObject = { {
    QMetaObject::SuperData::link<QAbstractListModel::staticMetaObject>(),
    qt_meta_stringdata_JPlaylistDataEntry.data,
    qt_meta_data_JPlaylistDataEntry,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *JPlaylistDataEntry::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *JPlaylistDataEntry::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_JPlaylistDataEntry.stringdata0))
        return static_cast<void*>(this);
    return QAbstractListModel::qt_metacast(_clname);
}

int JPlaylistDataEntry::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QAbstractListModel::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 4)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 4;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 4)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 4;
    }
#ifndef QT_NO_PROPERTIES
    else if (_c == QMetaObject::ReadProperty || _c == QMetaObject::WriteProperty
            || _c == QMetaObject::ResetProperty || _c == QMetaObject::RegisterPropertyMetaType) {
        qt_static_metacall(this, _c, _id, _a);
        _id -= 1;
    } else if (_c == QMetaObject::QueryPropertyDesignable) {
        _id -= 1;
    } else if (_c == QMetaObject::QueryPropertyScriptable) {
        _id -= 1;
    } else if (_c == QMetaObject::QueryPropertyStored) {
        _id -= 1;
    } else if (_c == QMetaObject::QueryPropertyEditable) {
        _id -= 1;
    } else if (_c == QMetaObject::QueryPropertyUser) {
        _id -= 1;
    }
#endif // QT_NO_PROPERTIES
    return _id;
}

// SIGNAL 0
void JPlaylistDataEntry::fetchHomePlaylistsFromRepo()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void JPlaylistDataEntry::countChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
