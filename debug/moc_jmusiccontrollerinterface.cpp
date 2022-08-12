/****************************************************************************
** Meta object code from reading C++ file 'jmusiccontrollerinterface.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.15.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../jmusiccontrollerinterface.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'jmusiccontrollerinterface.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.15.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_JMusicControllerInterface_t {
    QByteArrayData data[28];
    char stringdata0[399];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_JMusicControllerInterface_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_JMusicControllerInterface_t qt_meta_stringdata_JMusicControllerInterface = {
    {
QT_MOC_LITERAL(0, 0, 25), // "JMusicControllerInterface"
QT_MOC_LITERAL(1, 26, 11), // "QML.Element"
QT_MOC_LITERAL(2, 38, 4), // "auto"
QT_MOC_LITERAL(3, 43, 13), // "QML.Singleton"
QT_MOC_LITERAL(4, 57, 4), // "true"
QT_MOC_LITERAL(5, 62, 20), // "trackFetchedFromRepo"
QT_MOC_LITERAL(6, 83, 0), // ""
QT_MOC_LITERAL(7, 84, 8), // "trackMap"
QT_MOC_LITERAL(8, 93, 19), // "playingTrackFetched"
QT_MOC_LITERAL(9, 113, 20), // "activeTrackIdChanged"
QT_MOC_LITERAL(10, 134, 14), // "shuffleChanged"
QT_MOC_LITERAL(11, 149, 18), // "dynamicModeChanged"
QT_MOC_LITERAL(12, 168, 18), // "handleFetchedTrack"
QT_MOC_LITERAL(13, 187, 25), // "handleFetchedPlayingTrack"
QT_MOC_LITERAL(14, 213, 3), // "map"
QT_MOC_LITERAL(15, 217, 8), // "getTrack"
QT_MOC_LITERAL(16, 226, 7), // "trackId"
QT_MOC_LITERAL(17, 234, 15), // "getPlayingTrack"
QT_MOC_LITERAL(18, 250, 12), // "trackClicked"
QT_MOC_LITERAL(19, 263, 24), // "addTrackToRecentlyPlayed"
QT_MOC_LITERAL(20, 288, 18), // "addTrackToPlaylist"
QT_MOC_LITERAL(21, 307, 10), // "playlistId"
QT_MOC_LITERAL(22, 318, 13), // "addTrackToQue"
QT_MOC_LITERAL(23, 332, 18), // "addPlaylistToQueue"
QT_MOC_LITERAL(24, 351, 7), // "shuffle"
QT_MOC_LITERAL(25, 359, 13), // "toggleShuffle"
QT_MOC_LITERAL(26, 373, 13), // "activeTrackId"
QT_MOC_LITERAL(27, 387, 11) // "dynamicMode"

    },
    "JMusicControllerInterface\0QML.Element\0"
    "auto\0QML.Singleton\0true\0trackFetchedFromRepo\0"
    "\0trackMap\0playingTrackFetched\0"
    "activeTrackIdChanged\0shuffleChanged\0"
    "dynamicModeChanged\0handleFetchedTrack\0"
    "handleFetchedPlayingTrack\0map\0getTrack\0"
    "trackId\0getPlayingTrack\0trackClicked\0"
    "addTrackToRecentlyPlayed\0addTrackToPlaylist\0"
    "playlistId\0addTrackToQue\0addPlaylistToQueue\0"
    "shuffle\0toggleShuffle\0activeTrackId\0"
    "dynamicMode"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_JMusicControllerInterface[] = {

 // content:
       8,       // revision
       0,       // classname
       2,   14, // classinfo
      15,   18, // methods
       3,  134, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       5,       // signalCount

 // classinfo: key, value
       1,    2,
       3,    4,

 // signals: name, argc, parameters, tag, flags
       5,    1,   93,    6, 0x06 /* Public */,
       8,    1,   96,    6, 0x06 /* Public */,
       9,    0,   99,    6, 0x06 /* Public */,
      10,    0,  100,    6, 0x06 /* Public */,
      11,    0,  101,    6, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
      12,    1,  102,    6, 0x0a /* Public */,
      13,    1,  105,    6, 0x0a /* Public */,
      15,    1,  108,    6, 0x0a /* Public */,
      17,    1,  111,    6, 0x0a /* Public */,
      18,    1,  114,    6, 0x0a /* Public */,
      19,    1,  117,    6, 0x0a /* Public */,
      20,    2,  120,    6, 0x0a /* Public */,
      22,    1,  125,    6, 0x0a /* Public */,
      23,    2,  128,    6, 0x0a /* Public */,
      25,    0,  133,    6, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::QVariantMap,    7,
    QMetaType::Void, QMetaType::QVariantMap,    7,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void, QMetaType::QVariantMap,    7,
    QMetaType::Void, QMetaType::QVariantMap,   14,
    QMetaType::Void, QMetaType::Int,   16,
    QMetaType::Void, QMetaType::Int,   16,
    QMetaType::Void, QMetaType::Int,   16,
    QMetaType::Void, QMetaType::Int,   16,
    QMetaType::Void, QMetaType::Int, QMetaType::Int,   16,   21,
    QMetaType::Void, QMetaType::Int,   16,
    QMetaType::Void, QMetaType::Int, QMetaType::Bool,   21,   24,
    QMetaType::Void,

 // properties: name, type, flags
      24, QMetaType::Bool, 0x00495103,
      26, QMetaType::Int, 0x00495103,
      27, QMetaType::Bool, 0x00495103,

 // properties: notify_signal_id
       3,
       2,
       4,

       0        // eod
};

void JMusicControllerInterface::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<JMusicControllerInterface *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->trackFetchedFromRepo((*reinterpret_cast< QVariantMap(*)>(_a[1]))); break;
        case 1: _t->playingTrackFetched((*reinterpret_cast< QVariantMap(*)>(_a[1]))); break;
        case 2: _t->activeTrackIdChanged(); break;
        case 3: _t->shuffleChanged(); break;
        case 4: _t->dynamicModeChanged(); break;
        case 5: _t->handleFetchedTrack((*reinterpret_cast< QVariantMap(*)>(_a[1]))); break;
        case 6: _t->handleFetchedPlayingTrack((*reinterpret_cast< QVariantMap(*)>(_a[1]))); break;
        case 7: _t->getTrack((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 8: _t->getPlayingTrack((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 9: _t->trackClicked((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 10: _t->addTrackToRecentlyPlayed((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 11: _t->addTrackToPlaylist((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 12: _t->addTrackToQue((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 13: _t->addPlaylistToQueue((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< bool(*)>(_a[2]))); break;
        case 14: _t->toggleShuffle(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (JMusicControllerInterface::*)(QVariantMap );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&JMusicControllerInterface::trackFetchedFromRepo)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (JMusicControllerInterface::*)(QVariantMap );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&JMusicControllerInterface::playingTrackFetched)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (JMusicControllerInterface::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&JMusicControllerInterface::activeTrackIdChanged)) {
                *result = 2;
                return;
            }
        }
        {
            using _t = void (JMusicControllerInterface::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&JMusicControllerInterface::shuffleChanged)) {
                *result = 3;
                return;
            }
        }
        {
            using _t = void (JMusicControllerInterface::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&JMusicControllerInterface::dynamicModeChanged)) {
                *result = 4;
                return;
            }
        }
    }
#ifndef QT_NO_PROPERTIES
    else if (_c == QMetaObject::ReadProperty) {
        auto *_t = static_cast<JMusicControllerInterface *>(_o);
        Q_UNUSED(_t)
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast< bool*>(_v) = _t->getShuffle(); break;
        case 1: *reinterpret_cast< int*>(_v) = _t->getActiveTrackId(); break;
        case 2: *reinterpret_cast< bool*>(_v) = _t->getDynamicMode(); break;
        default: break;
        }
    } else if (_c == QMetaObject::WriteProperty) {
        auto *_t = static_cast<JMusicControllerInterface *>(_o);
        Q_UNUSED(_t)
        void *_v = _a[0];
        switch (_id) {
        case 0: _t->setShuffle(*reinterpret_cast< bool*>(_v)); break;
        case 1: _t->setActiveTrackId(*reinterpret_cast< int*>(_v)); break;
        case 2: _t->setDynamicMode(*reinterpret_cast< bool*>(_v)); break;
        default: break;
        }
    } else if (_c == QMetaObject::ResetProperty) {
    }
#endif // QT_NO_PROPERTIES
}

QT_INIT_METAOBJECT const QMetaObject JMusicControllerInterface::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_meta_stringdata_JMusicControllerInterface.data,
    qt_meta_data_JMusicControllerInterface,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *JMusicControllerInterface::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *JMusicControllerInterface::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_JMusicControllerInterface.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int JMusicControllerInterface::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 15)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 15;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 15)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 15;
    }
#ifndef QT_NO_PROPERTIES
    else if (_c == QMetaObject::ReadProperty || _c == QMetaObject::WriteProperty
            || _c == QMetaObject::ResetProperty || _c == QMetaObject::RegisterPropertyMetaType) {
        qt_static_metacall(this, _c, _id, _a);
        _id -= 3;
    } else if (_c == QMetaObject::QueryPropertyDesignable) {
        _id -= 3;
    } else if (_c == QMetaObject::QueryPropertyScriptable) {
        _id -= 3;
    } else if (_c == QMetaObject::QueryPropertyStored) {
        _id -= 3;
    } else if (_c == QMetaObject::QueryPropertyEditable) {
        _id -= 3;
    } else if (_c == QMetaObject::QueryPropertyUser) {
        _id -= 3;
    }
#endif // QT_NO_PROPERTIES
    return _id;
}

// SIGNAL 0
void JMusicControllerInterface::trackFetchedFromRepo(QVariantMap _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void JMusicControllerInterface::playingTrackFetched(QVariantMap _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void JMusicControllerInterface::activeTrackIdChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 2, nullptr);
}

// SIGNAL 3
void JMusicControllerInterface::shuffleChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 3, nullptr);
}

// SIGNAL 4
void JMusicControllerInterface::dynamicModeChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 4, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
