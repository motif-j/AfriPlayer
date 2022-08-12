/****************************************************************************
** Meta object code from reading C++ file 'jmusiccontroller.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.15.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../jmusiccontroller.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#include <QtCore/QList>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'jmusiccontroller.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.15.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_JMusicController_t {
    QByteArrayData data[57];
    char stringdata0[1021];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_JMusicController_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_JMusicController_t qt_meta_stringdata_JMusicController = {
    {
QT_MOC_LITERAL(0, 0, 16), // "JMusicController"
QT_MOC_LITERAL(1, 17, 24), // "fetchTrackFromRepository"
QT_MOC_LITERAL(2, 42, 0), // ""
QT_MOC_LITERAL(3, 43, 7), // "trackId"
QT_MOC_LITERAL(4, 51, 31), // "fetchPlayingTrackFromRepository"
QT_MOC_LITERAL(5, 83, 25), // "fetchTracksFromRepository"
QT_MOC_LITERAL(6, 109, 6), // "lastId"
QT_MOC_LITERAL(7, 116, 5), // "limit"
QT_MOC_LITERAL(8, 122, 31), // "fetchHomePlaylistFromRepository"
QT_MOC_LITERAL(9, 154, 27), // "fetchPlaylistTracksFromRepo"
QT_MOC_LITERAL(10, 182, 10), // "playlistId"
QT_MOC_LITERAL(11, 193, 11), // "refreshCode"
QT_MOC_LITERAL(12, 205, 25), // "fetchRecentlyPlayedTracks"
QT_MOC_LITERAL(13, 231, 21), // "addTrackToPlaylistSig"
QT_MOC_LITERAL(14, 253, 10), // "queueTrack"
QT_MOC_LITERAL(15, 264, 19), // "queuePlaylistTracks"
QT_MOC_LITERAL(16, 284, 6), // "append"
QT_MOC_LITERAL(17, 291, 17), // "fetchPlayingQueue"
QT_MOC_LITERAL(18, 309, 12), // "trackFetched"
QT_MOC_LITERAL(19, 322, 9), // "jsonTrack"
QT_MOC_LITERAL(20, 332, 19), // "playingTrackFetched"
QT_MOC_LITERAL(21, 352, 12), // "tracksLoaded"
QT_MOC_LITERAL(22, 365, 14), // "QList<JTrack>*"
QT_MOC_LITERAL(23, 380, 20), // "playlistTracksLoaded"
QT_MOC_LITERAL(24, 401, 27), // "recentlyPlayedTracksFetched"
QT_MOC_LITERAL(25, 429, 19), // "homePlaylistFetched"
QT_MOC_LITERAL(26, 449, 17), // "QList<JPlaylist>*"
QT_MOC_LITERAL(27, 467, 20), // "activeTrackIdChanged"
QT_MOC_LITERAL(28, 488, 10), // "newTrackID"
QT_MOC_LITERAL(29, 499, 19), // "queuedTracksFetched"
QT_MOC_LITERAL(30, 519, 11), // "trackQueued"
QT_MOC_LITERAL(31, 531, 6), // "JTrack"
QT_MOC_LITERAL(32, 538, 5), // "track"
QT_MOC_LITERAL(33, 544, 16), // "getActiveTrackId"
QT_MOC_LITERAL(34, 561, 16), // "setActiveTrackId"
QT_MOC_LITERAL(35, 578, 16), // "newActiveTrackId"
QT_MOC_LITERAL(36, 595, 8), // "getTrack"
QT_MOC_LITERAL(37, 604, 15), // "getPlayingTrack"
QT_MOC_LITERAL(38, 620, 10), // "loadTracks"
QT_MOC_LITERAL(39, 631, 16), // "loadHomePlaylist"
QT_MOC_LITERAL(40, 648, 17), // "loadPlaylistTrack"
QT_MOC_LITERAL(41, 666, 24), // "loadRecentlyPlayedTracks"
QT_MOC_LITERAL(42, 691, 18), // "addTrackToPlaylist"
QT_MOC_LITERAL(43, 710, 15), // "addTrackToQueue"
QT_MOC_LITERAL(44, 726, 18), // "addPlaylistToQueue"
QT_MOC_LITERAL(45, 745, 13), // "loadQueueList"
QT_MOC_LITERAL(46, 759, 16), // "handleFetchTrack"
QT_MOC_LITERAL(47, 776, 11), // "trackResult"
QT_MOC_LITERAL(48, 788, 25), // "handlePlayingTrackFetched"
QT_MOC_LITERAL(49, 814, 26), // "handleTracksFromRepository"
QT_MOC_LITERAL(50, 841, 35), // "handlePlaylistTracksFetchedFr..."
QT_MOC_LITERAL(51, 877, 40), // "handleHomePlaylistsFetchedFro..."
QT_MOC_LITERAL(52, 918, 6), // "result"
QT_MOC_LITERAL(53, 925, 33), // "handleRecentlyPlayedTracksFet..."
QT_MOC_LITERAL(54, 959, 25), // "handleQueuedTracksFetched"
QT_MOC_LITERAL(55, 985, 6), // "tracks"
QT_MOC_LITERAL(56, 992, 28) // "handleQueuedSoloTrackFetched"

    },
    "JMusicController\0fetchTrackFromRepository\0"
    "\0trackId\0fetchPlayingTrackFromRepository\0"
    "fetchTracksFromRepository\0lastId\0limit\0"
    "fetchHomePlaylistFromRepository\0"
    "fetchPlaylistTracksFromRepo\0playlistId\0"
    "refreshCode\0fetchRecentlyPlayedTracks\0"
    "addTrackToPlaylistSig\0queueTrack\0"
    "queuePlaylistTracks\0append\0fetchPlayingQueue\0"
    "trackFetched\0jsonTrack\0playingTrackFetched\0"
    "tracksLoaded\0QList<JTrack>*\0"
    "playlistTracksLoaded\0recentlyPlayedTracksFetched\0"
    "homePlaylistFetched\0QList<JPlaylist>*\0"
    "activeTrackIdChanged\0newTrackID\0"
    "queuedTracksFetched\0trackQueued\0JTrack\0"
    "track\0getActiveTrackId\0setActiveTrackId\0"
    "newActiveTrackId\0getTrack\0getPlayingTrack\0"
    "loadTracks\0loadHomePlaylist\0"
    "loadPlaylistTrack\0loadRecentlyPlayedTracks\0"
    "addTrackToPlaylist\0addTrackToQueue\0"
    "addPlaylistToQueue\0loadQueueList\0"
    "handleFetchTrack\0trackResult\0"
    "handlePlayingTrackFetched\0"
    "handleTracksFromRepository\0"
    "handlePlaylistTracksFetchedFromRepo\0"
    "handleHomePlaylistsFetchedFromRepository\0"
    "result\0handleRecentlyPlayedTracksFetched\0"
    "handleQueuedTracksFetched\0tracks\0"
    "handleQueuedSoloTrackFetched"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_JMusicController[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      39,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
      19,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,  209,    2, 0x06 /* Public */,
       4,    1,  212,    2, 0x06 /* Public */,
       5,    2,  215,    2, 0x06 /* Public */,
       8,    0,  220,    2, 0x06 /* Public */,
       9,    2,  221,    2, 0x06 /* Public */,
      12,    0,  226,    2, 0x06 /* Public */,
      13,    2,  227,    2, 0x06 /* Public */,
      14,    1,  232,    2, 0x06 /* Public */,
      15,    2,  235,    2, 0x06 /* Public */,
      17,    0,  240,    2, 0x06 /* Public */,
      18,    1,  241,    2, 0x06 /* Public */,
      20,    1,  244,    2, 0x06 /* Public */,
      21,    1,  247,    2, 0x06 /* Public */,
      23,    1,  250,    2, 0x06 /* Public */,
      24,    1,  253,    2, 0x06 /* Public */,
      25,    1,  256,    2, 0x06 /* Public */,
      27,    1,  259,    2, 0x06 /* Public */,
      29,    1,  262,    2, 0x06 /* Public */,
      30,    1,  265,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
      33,    0,  268,    2, 0x0a /* Public */,
      34,    1,  269,    2, 0x0a /* Public */,
      36,    1,  272,    2, 0x0a /* Public */,
      37,    1,  275,    2, 0x0a /* Public */,
      38,    2,  278,    2, 0x0a /* Public */,
      39,    0,  283,    2, 0x0a /* Public */,
      40,    2,  284,    2, 0x0a /* Public */,
      41,    0,  289,    2, 0x0a /* Public */,
      42,    2,  290,    2, 0x0a /* Public */,
      43,    1,  295,    2, 0x0a /* Public */,
      44,    2,  298,    2, 0x0a /* Public */,
      45,    0,  303,    2, 0x0a /* Public */,
      46,    1,  304,    2, 0x0a /* Public */,
      48,    1,  307,    2, 0x0a /* Public */,
      49,    1,  310,    2, 0x0a /* Public */,
      50,    1,  313,    2, 0x0a /* Public */,
      51,    1,  316,    2, 0x0a /* Public */,
      53,    1,  319,    2, 0x0a /* Public */,
      54,    1,  322,    2, 0x0a /* Public */,
      56,    1,  325,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::Int,    3,
    QMetaType::Void, QMetaType::Int,    3,
    QMetaType::Void, QMetaType::Int, QMetaType::Int,    6,    7,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int, QMetaType::Int,   10,   11,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int, QMetaType::Int,    3,   10,
    QMetaType::Void, QMetaType::Int,    3,
    QMetaType::Void, QMetaType::Int, QMetaType::Bool,   10,   16,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QVariantMap,   19,
    QMetaType::Void, QMetaType::QVariantMap,   19,
    QMetaType::Void, 0x80000000 | 22,    2,
    QMetaType::Void, 0x80000000 | 22,    2,
    QMetaType::Void, 0x80000000 | 22,    2,
    QMetaType::Void, 0x80000000 | 26,    2,
    QMetaType::Void, QMetaType::Int,   28,
    QMetaType::Void, 0x80000000 | 22,    2,
    QMetaType::Void, 0x80000000 | 31,   32,

 // slots: parameters
    QMetaType::Int,
    QMetaType::Void, QMetaType::Int,   35,
    QMetaType::Void, QMetaType::Int,    3,
    QMetaType::Void, QMetaType::Int,    3,
    QMetaType::Void, QMetaType::Int, QMetaType::Int,    6,    7,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int, QMetaType::Int,   10,   11,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int, QMetaType::Int,    3,   10,
    QMetaType::Void, QMetaType::Int,    3,
    QMetaType::Void, QMetaType::Int, QMetaType::Bool,   10,   16,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 31,   47,
    QMetaType::Void, 0x80000000 | 31,   32,
    QMetaType::Void, 0x80000000 | 22,    2,
    QMetaType::Void, 0x80000000 | 22,    2,
    QMetaType::Void, 0x80000000 | 26,   52,
    QMetaType::Void, 0x80000000 | 22,    2,
    QMetaType::Void, 0x80000000 | 22,   55,
    QMetaType::Void, 0x80000000 | 31,   32,

       0        // eod
};

void JMusicController::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<JMusicController *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->fetchTrackFromRepository((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 1: _t->fetchPlayingTrackFromRepository((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 2: _t->fetchTracksFromRepository((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 3: _t->fetchHomePlaylistFromRepository(); break;
        case 4: _t->fetchPlaylistTracksFromRepo((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 5: _t->fetchRecentlyPlayedTracks(); break;
        case 6: _t->addTrackToPlaylistSig((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 7: _t->queueTrack((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 8: _t->queuePlaylistTracks((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< bool(*)>(_a[2]))); break;
        case 9: _t->fetchPlayingQueue(); break;
        case 10: _t->trackFetched((*reinterpret_cast< QVariantMap(*)>(_a[1]))); break;
        case 11: _t->playingTrackFetched((*reinterpret_cast< QVariantMap(*)>(_a[1]))); break;
        case 12: _t->tracksLoaded((*reinterpret_cast< QList<JTrack>*(*)>(_a[1]))); break;
        case 13: _t->playlistTracksLoaded((*reinterpret_cast< QList<JTrack>*(*)>(_a[1]))); break;
        case 14: _t->recentlyPlayedTracksFetched((*reinterpret_cast< QList<JTrack>*(*)>(_a[1]))); break;
        case 15: _t->homePlaylistFetched((*reinterpret_cast< QList<JPlaylist>*(*)>(_a[1]))); break;
        case 16: _t->activeTrackIdChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 17: _t->queuedTracksFetched((*reinterpret_cast< QList<JTrack>*(*)>(_a[1]))); break;
        case 18: _t->trackQueued((*reinterpret_cast< JTrack(*)>(_a[1]))); break;
        case 19: { int _r = _t->getActiveTrackId();
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = std::move(_r); }  break;
        case 20: _t->setActiveTrackId((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 21: _t->getTrack((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 22: _t->getPlayingTrack((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 23: _t->loadTracks((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 24: _t->loadHomePlaylist(); break;
        case 25: _t->loadPlaylistTrack((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 26: _t->loadRecentlyPlayedTracks(); break;
        case 27: _t->addTrackToPlaylist((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 28: _t->addTrackToQueue((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 29: _t->addPlaylistToQueue((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< bool(*)>(_a[2]))); break;
        case 30: _t->loadQueueList(); break;
        case 31: _t->handleFetchTrack((*reinterpret_cast< JTrack(*)>(_a[1]))); break;
        case 32: _t->handlePlayingTrackFetched((*reinterpret_cast< JTrack(*)>(_a[1]))); break;
        case 33: _t->handleTracksFromRepository((*reinterpret_cast< QList<JTrack>*(*)>(_a[1]))); break;
        case 34: _t->handlePlaylistTracksFetchedFromRepo((*reinterpret_cast< QList<JTrack>*(*)>(_a[1]))); break;
        case 35: _t->handleHomePlaylistsFetchedFromRepository((*reinterpret_cast< QList<JPlaylist>*(*)>(_a[1]))); break;
        case 36: _t->handleRecentlyPlayedTracksFetched((*reinterpret_cast< QList<JTrack>*(*)>(_a[1]))); break;
        case 37: _t->handleQueuedTracksFetched((*reinterpret_cast< QList<JTrack>*(*)>(_a[1]))); break;
        case 38: _t->handleQueuedSoloTrackFetched((*reinterpret_cast< JTrack(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (JMusicController::*)(int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&JMusicController::fetchTrackFromRepository)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (JMusicController::*)(int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&JMusicController::fetchPlayingTrackFromRepository)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (JMusicController::*)(int , int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&JMusicController::fetchTracksFromRepository)) {
                *result = 2;
                return;
            }
        }
        {
            using _t = void (JMusicController::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&JMusicController::fetchHomePlaylistFromRepository)) {
                *result = 3;
                return;
            }
        }
        {
            using _t = void (JMusicController::*)(int , int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&JMusicController::fetchPlaylistTracksFromRepo)) {
                *result = 4;
                return;
            }
        }
        {
            using _t = void (JMusicController::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&JMusicController::fetchRecentlyPlayedTracks)) {
                *result = 5;
                return;
            }
        }
        {
            using _t = void (JMusicController::*)(int , int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&JMusicController::addTrackToPlaylistSig)) {
                *result = 6;
                return;
            }
        }
        {
            using _t = void (JMusicController::*)(int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&JMusicController::queueTrack)) {
                *result = 7;
                return;
            }
        }
        {
            using _t = void (JMusicController::*)(int , bool );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&JMusicController::queuePlaylistTracks)) {
                *result = 8;
                return;
            }
        }
        {
            using _t = void (JMusicController::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&JMusicController::fetchPlayingQueue)) {
                *result = 9;
                return;
            }
        }
        {
            using _t = void (JMusicController::*)(QVariantMap );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&JMusicController::trackFetched)) {
                *result = 10;
                return;
            }
        }
        {
            using _t = void (JMusicController::*)(QVariantMap );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&JMusicController::playingTrackFetched)) {
                *result = 11;
                return;
            }
        }
        {
            using _t = void (JMusicController::*)(QList<JTrack> * );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&JMusicController::tracksLoaded)) {
                *result = 12;
                return;
            }
        }
        {
            using _t = void (JMusicController::*)(QList<JTrack> * );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&JMusicController::playlistTracksLoaded)) {
                *result = 13;
                return;
            }
        }
        {
            using _t = void (JMusicController::*)(QList<JTrack> * );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&JMusicController::recentlyPlayedTracksFetched)) {
                *result = 14;
                return;
            }
        }
        {
            using _t = void (JMusicController::*)(QList<JPlaylist> * );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&JMusicController::homePlaylistFetched)) {
                *result = 15;
                return;
            }
        }
        {
            using _t = void (JMusicController::*)(int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&JMusicController::activeTrackIdChanged)) {
                *result = 16;
                return;
            }
        }
        {
            using _t = void (JMusicController::*)(QList<JTrack> * );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&JMusicController::queuedTracksFetched)) {
                *result = 17;
                return;
            }
        }
        {
            using _t = void (JMusicController::*)(JTrack );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&JMusicController::trackQueued)) {
                *result = 18;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject JMusicController::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_meta_stringdata_JMusicController.data,
    qt_meta_data_JMusicController,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *JMusicController::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *JMusicController::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_JMusicController.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int JMusicController::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 39)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 39;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 39)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 39;
    }
    return _id;
}

// SIGNAL 0
void JMusicController::fetchTrackFromRepository(int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void JMusicController::fetchPlayingTrackFromRepository(int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void JMusicController::fetchTracksFromRepository(int _t1, int _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void JMusicController::fetchHomePlaylistFromRepository()
{
    QMetaObject::activate(this, &staticMetaObject, 3, nullptr);
}

// SIGNAL 4
void JMusicController::fetchPlaylistTracksFromRepo(int _t1, int _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))) };
    QMetaObject::activate(this, &staticMetaObject, 4, _a);
}

// SIGNAL 5
void JMusicController::fetchRecentlyPlayedTracks()
{
    QMetaObject::activate(this, &staticMetaObject, 5, nullptr);
}

// SIGNAL 6
void JMusicController::addTrackToPlaylistSig(int _t1, int _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))) };
    QMetaObject::activate(this, &staticMetaObject, 6, _a);
}

// SIGNAL 7
void JMusicController::queueTrack(int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 7, _a);
}

// SIGNAL 8
void JMusicController::queuePlaylistTracks(int _t1, bool _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))) };
    QMetaObject::activate(this, &staticMetaObject, 8, _a);
}

// SIGNAL 9
void JMusicController::fetchPlayingQueue()
{
    QMetaObject::activate(this, &staticMetaObject, 9, nullptr);
}

// SIGNAL 10
void JMusicController::trackFetched(QVariantMap _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 10, _a);
}

// SIGNAL 11
void JMusicController::playingTrackFetched(QVariantMap _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 11, _a);
}

// SIGNAL 12
void JMusicController::tracksLoaded(QList<JTrack> * _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 12, _a);
}

// SIGNAL 13
void JMusicController::playlistTracksLoaded(QList<JTrack> * _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 13, _a);
}

// SIGNAL 14
void JMusicController::recentlyPlayedTracksFetched(QList<JTrack> * _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 14, _a);
}

// SIGNAL 15
void JMusicController::homePlaylistFetched(QList<JPlaylist> * _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 15, _a);
}

// SIGNAL 16
void JMusicController::activeTrackIdChanged(int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 16, _a);
}

// SIGNAL 17
void JMusicController::queuedTracksFetched(QList<JTrack> * _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 17, _a);
}

// SIGNAL 18
void JMusicController::trackQueued(JTrack _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 18, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
