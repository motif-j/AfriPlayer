/****************************************************************************
** Meta object code from reading C++ file 'jmusiccontrollerworker.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.15.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../jmusiccontrollerworker.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#include <QtCore/QList>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'jmusiccontrollerworker.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.15.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_JMusicControllerWorker_t {
    QByteArrayData data[30];
    char stringdata0[505];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_JMusicControllerWorker_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_JMusicControllerWorker_t qt_meta_stringdata_JMusicControllerWorker = {
    {
QT_MOC_LITERAL(0, 0, 22), // "JMusicControllerWorker"
QT_MOC_LITERAL(1, 23, 12), // "trackFetched"
QT_MOC_LITERAL(2, 36, 0), // ""
QT_MOC_LITERAL(3, 37, 6), // "JTrack"
QT_MOC_LITERAL(4, 44, 5), // "track"
QT_MOC_LITERAL(5, 50, 19), // "playingTrackFetched"
QT_MOC_LITERAL(6, 70, 27), // "tracksFetchedFromRepository"
QT_MOC_LITERAL(7, 98, 14), // "QList<JTrack>*"
QT_MOC_LITERAL(8, 113, 29), // "playlistTracksFetchedFromRepo"
QT_MOC_LITERAL(9, 143, 33), // "homePlaylistFetchedFromReposi..."
QT_MOC_LITERAL(10, 177, 17), // "QList<JPlaylist>*"
QT_MOC_LITERAL(11, 195, 27), // "recentlyPlayedTracksFetched"
QT_MOC_LITERAL(12, 223, 19), // "queuedTracksFetched"
QT_MOC_LITERAL(13, 243, 11), // "trackQueued"
QT_MOC_LITERAL(14, 255, 8), // "getTrack"
QT_MOC_LITERAL(15, 264, 7), // "trackId"
QT_MOC_LITERAL(16, 272, 15), // "getPlayingTrack"
QT_MOC_LITERAL(17, 288, 25), // "fetchTracksFromRepository"
QT_MOC_LITERAL(18, 314, 6), // "lastId"
QT_MOC_LITERAL(19, 321, 5), // "limit"
QT_MOC_LITERAL(20, 327, 25), // "fetchHomePlaylistFromRepo"
QT_MOC_LITERAL(21, 353, 27), // "fetchPlaylistTracksFromRepo"
QT_MOC_LITERAL(22, 381, 10), // "playlistId"
QT_MOC_LITERAL(23, 392, 11), // "refreshCode"
QT_MOC_LITERAL(24, 404, 25), // "fetchRecentlyPlayedTracks"
QT_MOC_LITERAL(25, 430, 18), // "addTrackToPlaylist"
QT_MOC_LITERAL(26, 449, 10), // "queueTrack"
QT_MOC_LITERAL(27, 460, 17), // "fetchPlayingQueue"
QT_MOC_LITERAL(28, 478, 19), // "queuePlaylistTracks"
QT_MOC_LITERAL(29, 498, 6) // "append"

    },
    "JMusicControllerWorker\0trackFetched\0"
    "\0JTrack\0track\0playingTrackFetched\0"
    "tracksFetchedFromRepository\0QList<JTrack>*\0"
    "playlistTracksFetchedFromRepo\0"
    "homePlaylistFetchedFromRepository\0"
    "QList<JPlaylist>*\0recentlyPlayedTracksFetched\0"
    "queuedTracksFetched\0trackQueued\0"
    "getTrack\0trackId\0getPlayingTrack\0"
    "fetchTracksFromRepository\0lastId\0limit\0"
    "fetchHomePlaylistFromRepo\0"
    "fetchPlaylistTracksFromRepo\0playlistId\0"
    "refreshCode\0fetchRecentlyPlayedTracks\0"
    "addTrackToPlaylist\0queueTrack\0"
    "fetchPlayingQueue\0queuePlaylistTracks\0"
    "append"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_JMusicControllerWorker[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      18,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       8,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,  104,    2, 0x06 /* Public */,
       5,    1,  107,    2, 0x06 /* Public */,
       6,    1,  110,    2, 0x06 /* Public */,
       8,    1,  113,    2, 0x06 /* Public */,
       9,    1,  116,    2, 0x06 /* Public */,
      11,    1,  119,    2, 0x06 /* Public */,
      12,    1,  122,    2, 0x06 /* Public */,
      13,    1,  125,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
      14,    1,  128,    2, 0x0a /* Public */,
      16,    1,  131,    2, 0x0a /* Public */,
      17,    2,  134,    2, 0x0a /* Public */,
      20,    0,  139,    2, 0x0a /* Public */,
      21,    2,  140,    2, 0x0a /* Public */,
      24,    0,  145,    2, 0x0a /* Public */,
      25,    2,  146,    2, 0x0a /* Public */,
      26,    1,  151,    2, 0x0a /* Public */,
      27,    0,  154,    2, 0x0a /* Public */,
      28,    2,  155,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3,    4,
    QMetaType::Void, 0x80000000 | 3,    4,
    QMetaType::Void, 0x80000000 | 7,    2,
    QMetaType::Void, 0x80000000 | 7,    2,
    QMetaType::Void, 0x80000000 | 10,    2,
    QMetaType::Void, 0x80000000 | 7,    2,
    QMetaType::Void, 0x80000000 | 7,    2,
    QMetaType::Void, 0x80000000 | 3,    4,

 // slots: parameters
    QMetaType::Void, QMetaType::Int,   15,
    QMetaType::Void, QMetaType::Int,   15,
    QMetaType::Void, QMetaType::Int, QMetaType::Int,   18,   19,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int, QMetaType::Int,   22,   23,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int, QMetaType::Int,   15,   22,
    QMetaType::Void, QMetaType::Int,   15,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int, QMetaType::Bool,   22,   29,

       0        // eod
};

void JMusicControllerWorker::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<JMusicControllerWorker *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->trackFetched((*reinterpret_cast< JTrack(*)>(_a[1]))); break;
        case 1: _t->playingTrackFetched((*reinterpret_cast< JTrack(*)>(_a[1]))); break;
        case 2: _t->tracksFetchedFromRepository((*reinterpret_cast< QList<JTrack>*(*)>(_a[1]))); break;
        case 3: _t->playlistTracksFetchedFromRepo((*reinterpret_cast< QList<JTrack>*(*)>(_a[1]))); break;
        case 4: _t->homePlaylistFetchedFromRepository((*reinterpret_cast< QList<JPlaylist>*(*)>(_a[1]))); break;
        case 5: _t->recentlyPlayedTracksFetched((*reinterpret_cast< QList<JTrack>*(*)>(_a[1]))); break;
        case 6: _t->queuedTracksFetched((*reinterpret_cast< QList<JTrack>*(*)>(_a[1]))); break;
        case 7: _t->trackQueued((*reinterpret_cast< JTrack(*)>(_a[1]))); break;
        case 8: _t->getTrack((*reinterpret_cast< const int(*)>(_a[1]))); break;
        case 9: _t->getPlayingTrack((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 10: _t->fetchTracksFromRepository((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 11: _t->fetchHomePlaylistFromRepo(); break;
        case 12: _t->fetchPlaylistTracksFromRepo((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 13: _t->fetchRecentlyPlayedTracks(); break;
        case 14: _t->addTrackToPlaylist((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 15: _t->queueTrack((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 16: _t->fetchPlayingQueue(); break;
        case 17: _t->queuePlaylistTracks((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< bool(*)>(_a[2]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (JMusicControllerWorker::*)(JTrack );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&JMusicControllerWorker::trackFetched)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (JMusicControllerWorker::*)(JTrack );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&JMusicControllerWorker::playingTrackFetched)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (JMusicControllerWorker::*)(QList<JTrack> * );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&JMusicControllerWorker::tracksFetchedFromRepository)) {
                *result = 2;
                return;
            }
        }
        {
            using _t = void (JMusicControllerWorker::*)(QList<JTrack> * );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&JMusicControllerWorker::playlistTracksFetchedFromRepo)) {
                *result = 3;
                return;
            }
        }
        {
            using _t = void (JMusicControllerWorker::*)(QList<JPlaylist> * );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&JMusicControllerWorker::homePlaylistFetchedFromRepository)) {
                *result = 4;
                return;
            }
        }
        {
            using _t = void (JMusicControllerWorker::*)(QList<JTrack> * );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&JMusicControllerWorker::recentlyPlayedTracksFetched)) {
                *result = 5;
                return;
            }
        }
        {
            using _t = void (JMusicControllerWorker::*)(QList<JTrack> * );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&JMusicControllerWorker::queuedTracksFetched)) {
                *result = 6;
                return;
            }
        }
        {
            using _t = void (JMusicControllerWorker::*)(JTrack );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&JMusicControllerWorker::trackQueued)) {
                *result = 7;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject JMusicControllerWorker::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_meta_stringdata_JMusicControllerWorker.data,
    qt_meta_data_JMusicControllerWorker,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *JMusicControllerWorker::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *JMusicControllerWorker::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_JMusicControllerWorker.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int JMusicControllerWorker::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 18)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 18;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 18)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 18;
    }
    return _id;
}

// SIGNAL 0
void JMusicControllerWorker::trackFetched(JTrack _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void JMusicControllerWorker::playingTrackFetched(JTrack _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void JMusicControllerWorker::tracksFetchedFromRepository(QList<JTrack> * _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void JMusicControllerWorker::playlistTracksFetchedFromRepo(QList<JTrack> * _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}

// SIGNAL 4
void JMusicControllerWorker::homePlaylistFetchedFromRepository(QList<JPlaylist> * _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 4, _a);
}

// SIGNAL 5
void JMusicControllerWorker::recentlyPlayedTracksFetched(QList<JTrack> * _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 5, _a);
}

// SIGNAL 6
void JMusicControllerWorker::queuedTracksFetched(QList<JTrack> * _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 6, _a);
}

// SIGNAL 7
void JMusicControllerWorker::trackQueued(JTrack _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 7, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
