/****************************************************************************
** Meta object code from reading C++ file 'dm_tracksdataentry.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.15.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../dm_tracksdataentry.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#include <QtCore/QList>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'dm_tracksdataentry.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.15.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_TracksDataEntry_t {
    QByteArrayData data[52];
    char stringdata0[805];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_TracksDataEntry_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_TracksDataEntry_t qt_meta_stringdata_TracksDataEntry = {
    {
QT_MOC_LITERAL(0, 0, 15), // "TracksDataEntry"
QT_MOC_LITERAL(1, 16, 12), // "countChanged"
QT_MOC_LITERAL(2, 29, 0), // ""
QT_MOC_LITERAL(3, 30, 5), // "count"
QT_MOC_LITERAL(4, 36, 19), // "doneFetchingChanged"
QT_MOC_LITERAL(5, 56, 16), // "isLoadingChanged"
QT_MOC_LITERAL(6, 73, 18), // "activeIndexChanged"
QT_MOC_LITERAL(7, 92, 20), // "activeTrackIdChanged"
QT_MOC_LITERAL(8, 113, 5), // "newId"
QT_MOC_LITERAL(9, 119, 11), // "fetchTracks"
QT_MOC_LITERAL(10, 131, 6), // "lastId"
QT_MOC_LITERAL(11, 138, 5), // "limit"
QT_MOC_LITERAL(12, 144, 19), // "fetchPlaylistTracks"
QT_MOC_LITERAL(13, 164, 10), // "playlistId"
QT_MOC_LITERAL(14, 175, 11), // "refreshCode"
QT_MOC_LITERAL(15, 187, 25), // "fetchRecentlyPlayedTracks"
QT_MOC_LITERAL(16, 213, 21), // "addTrackToPlaylistSig"
QT_MOC_LITERAL(17, 235, 7), // "trackId"
QT_MOC_LITERAL(18, 243, 19), // "loadQueuedTracksSig"
QT_MOC_LITERAL(19, 263, 16), // "addTrackToQueSig"
QT_MOC_LITERAL(20, 280, 14), // "loadMoreTracks"
QT_MOC_LITERAL(21, 295, 18), // "loadPlaylistTracks"
QT_MOC_LITERAL(22, 314, 24), // "loadRecentlyPlayedTracks"
QT_MOC_LITERAL(23, 339, 13), // "clearPlaylist"
QT_MOC_LITERAL(24, 353, 24), // "addTrackToRecentlyPlayed"
QT_MOC_LITERAL(25, 378, 18), // "addTrackToPlaylist"
QT_MOC_LITERAL(26, 397, 14), // "loadQuedTracks"
QT_MOC_LITERAL(27, 412, 13), // "addTrackToQue"
QT_MOC_LITERAL(28, 426, 14), // "incrementIndex"
QT_MOC_LITERAL(29, 441, 14), // "decrementIndex"
QT_MOC_LITERAL(30, 456, 12), // "newListIndex"
QT_MOC_LITERAL(31, 469, 8), // "newIndex"
QT_MOC_LITERAL(32, 478, 8), // "playNext"
QT_MOC_LITERAL(33, 487, 12), // "playPrevious"
QT_MOC_LITERAL(34, 500, 15), // "playQueuedTrack"
QT_MOC_LITERAL(35, 516, 19), // "handleFetchedTracks"
QT_MOC_LITERAL(36, 536, 14), // "QList<JTrack>*"
QT_MOC_LITERAL(37, 551, 6), // "tracks"
QT_MOC_LITERAL(38, 558, 26), // "handleFetchedPlaylstTracks"
QT_MOC_LITERAL(39, 585, 26), // "handleActiveTrackIdChanged"
QT_MOC_LITERAL(40, 612, 27), // "handleRecentlyFetchedTracks"
QT_MOC_LITERAL(41, 640, 25), // "handlePlayingTrackFetched"
QT_MOC_LITERAL(42, 666, 8), // "trackMap"
QT_MOC_LITERAL(43, 675, 25), // "handleQueuedTracksFetched"
QT_MOC_LITERAL(44, 701, 12), // "queuedTracks"
QT_MOC_LITERAL(45, 714, 28), // "handleSoloQueuedTrackFetched"
QT_MOC_LITERAL(46, 743, 6), // "JTrack"
QT_MOC_LITERAL(47, 750, 5), // "track"
QT_MOC_LITERAL(48, 756, 12), // "doneFetching"
QT_MOC_LITERAL(49, 769, 9), // "isLoading"
QT_MOC_LITERAL(50, 779, 13), // "activeTrackId"
QT_MOC_LITERAL(51, 793, 11) // "activeIndex"

    },
    "TracksDataEntry\0countChanged\0\0count\0"
    "doneFetchingChanged\0isLoadingChanged\0"
    "activeIndexChanged\0activeTrackIdChanged\0"
    "newId\0fetchTracks\0lastId\0limit\0"
    "fetchPlaylistTracks\0playlistId\0"
    "refreshCode\0fetchRecentlyPlayedTracks\0"
    "addTrackToPlaylistSig\0trackId\0"
    "loadQueuedTracksSig\0addTrackToQueSig\0"
    "loadMoreTracks\0loadPlaylistTracks\0"
    "loadRecentlyPlayedTracks\0clearPlaylist\0"
    "addTrackToRecentlyPlayed\0addTrackToPlaylist\0"
    "loadQuedTracks\0addTrackToQue\0"
    "incrementIndex\0decrementIndex\0"
    "newListIndex\0newIndex\0playNext\0"
    "playPrevious\0playQueuedTrack\0"
    "handleFetchedTracks\0QList<JTrack>*\0"
    "tracks\0handleFetchedPlaylstTracks\0"
    "handleActiveTrackIdChanged\0"
    "handleRecentlyFetchedTracks\0"
    "handlePlayingTrackFetched\0trackMap\0"
    "handleQueuedTracksFetched\0queuedTracks\0"
    "handleSoloQueuedTrackFetched\0JTrack\0"
    "track\0doneFetching\0isLoading\0activeTrackId\0"
    "activeIndex"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_TracksDataEntry[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      32,   14, // methods
       5,  254, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
      11,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,  174,    2, 0x06 /* Public */,
       4,    0,  177,    2, 0x06 /* Public */,
       5,    0,  178,    2, 0x06 /* Public */,
       6,    0,  179,    2, 0x06 /* Public */,
       7,    1,  180,    2, 0x06 /* Public */,
       9,    2,  183,    2, 0x06 /* Public */,
      12,    2,  188,    2, 0x06 /* Public */,
      15,    0,  193,    2, 0x06 /* Public */,
      16,    2,  194,    2, 0x06 /* Public */,
      18,    0,  199,    2, 0x06 /* Public */,
      19,    1,  200,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
      20,    0,  203,    2, 0x0a /* Public */,
      21,    2,  204,    2, 0x0a /* Public */,
      22,    0,  209,    2, 0x0a /* Public */,
      23,    0,  210,    2, 0x0a /* Public */,
      24,    1,  211,    2, 0x0a /* Public */,
      25,    2,  214,    2, 0x0a /* Public */,
      26,    0,  219,    2, 0x0a /* Public */,
      27,    1,  220,    2, 0x0a /* Public */,
      28,    0,  223,    2, 0x0a /* Public */,
      29,    0,  224,    2, 0x0a /* Public */,
      30,    1,  225,    2, 0x0a /* Public */,
      32,    0,  228,    2, 0x0a /* Public */,
      33,    0,  229,    2, 0x0a /* Public */,
      34,    1,  230,    2, 0x0a /* Public */,
      35,    1,  233,    2, 0x0a /* Public */,
      38,    1,  236,    2, 0x0a /* Public */,
      39,    1,  239,    2, 0x0a /* Public */,
      40,    1,  242,    2, 0x0a /* Public */,
      41,    1,  245,    2, 0x0a /* Public */,
      43,    1,  248,    2, 0x0a /* Public */,
      45,    1,  251,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::Int,    3,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,    8,
    QMetaType::Void, QMetaType::Int, QMetaType::Int,   10,   11,
    QMetaType::Void, QMetaType::Int, QMetaType::Int,   13,   14,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int, QMetaType::Int,   17,   13,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,   17,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int, QMetaType::Int,   13,   14,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,   17,
    QMetaType::Void, QMetaType::Int, QMetaType::Int,   17,   13,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,   17,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,   31,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,   17,
    QMetaType::Void, 0x80000000 | 36,   37,
    QMetaType::Void, 0x80000000 | 36,    2,
    QMetaType::Void, QMetaType::Int,    8,
    QMetaType::Void, 0x80000000 | 36,    2,
    QMetaType::Void, QMetaType::QVariantMap,   42,
    QMetaType::Void, 0x80000000 | 36,   44,
    QMetaType::Void, 0x80000000 | 46,   47,

 // properties: name, type, flags
       3, QMetaType::Int, 0x00495107,
      48, QMetaType::Bool, 0x00495103,
      49, QMetaType::Bool, 0x00495103,
      50, QMetaType::Int, 0x00495103,
      51, QMetaType::Int, 0x00495103,

 // properties: notify_signal_id
       0,
       1,
       2,
       4,
       3,

       0        // eod
};

void TracksDataEntry::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<TracksDataEntry *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->countChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 1: _t->doneFetchingChanged(); break;
        case 2: _t->isLoadingChanged(); break;
        case 3: _t->activeIndexChanged(); break;
        case 4: _t->activeTrackIdChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 5: _t->fetchTracks((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 6: _t->fetchPlaylistTracks((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 7: _t->fetchRecentlyPlayedTracks(); break;
        case 8: _t->addTrackToPlaylistSig((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 9: _t->loadQueuedTracksSig(); break;
        case 10: _t->addTrackToQueSig((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 11: _t->loadMoreTracks(); break;
        case 12: _t->loadPlaylistTracks((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 13: _t->loadRecentlyPlayedTracks(); break;
        case 14: _t->clearPlaylist(); break;
        case 15: _t->addTrackToRecentlyPlayed((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 16: _t->addTrackToPlaylist((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 17: _t->loadQuedTracks(); break;
        case 18: _t->addTrackToQue((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 19: _t->incrementIndex(); break;
        case 20: _t->decrementIndex(); break;
        case 21: _t->newListIndex((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 22: _t->playNext(); break;
        case 23: _t->playPrevious(); break;
        case 24: _t->playQueuedTrack((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 25: _t->handleFetchedTracks((*reinterpret_cast< QList<JTrack>*(*)>(_a[1]))); break;
        case 26: _t->handleFetchedPlaylstTracks((*reinterpret_cast< QList<JTrack>*(*)>(_a[1]))); break;
        case 27: _t->handleActiveTrackIdChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 28: _t->handleRecentlyFetchedTracks((*reinterpret_cast< QList<JTrack>*(*)>(_a[1]))); break;
        case 29: _t->handlePlayingTrackFetched((*reinterpret_cast< QVariantMap(*)>(_a[1]))); break;
        case 30: _t->handleQueuedTracksFetched((*reinterpret_cast< QList<JTrack>*(*)>(_a[1]))); break;
        case 31: _t->handleSoloQueuedTrackFetched((*reinterpret_cast< JTrack(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (TracksDataEntry::*)(int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&TracksDataEntry::countChanged)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (TracksDataEntry::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&TracksDataEntry::doneFetchingChanged)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (TracksDataEntry::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&TracksDataEntry::isLoadingChanged)) {
                *result = 2;
                return;
            }
        }
        {
            using _t = void (TracksDataEntry::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&TracksDataEntry::activeIndexChanged)) {
                *result = 3;
                return;
            }
        }
        {
            using _t = void (TracksDataEntry::*)(int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&TracksDataEntry::activeTrackIdChanged)) {
                *result = 4;
                return;
            }
        }
        {
            using _t = void (TracksDataEntry::*)(int , int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&TracksDataEntry::fetchTracks)) {
                *result = 5;
                return;
            }
        }
        {
            using _t = void (TracksDataEntry::*)(int , int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&TracksDataEntry::fetchPlaylistTracks)) {
                *result = 6;
                return;
            }
        }
        {
            using _t = void (TracksDataEntry::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&TracksDataEntry::fetchRecentlyPlayedTracks)) {
                *result = 7;
                return;
            }
        }
        {
            using _t = void (TracksDataEntry::*)(int , int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&TracksDataEntry::addTrackToPlaylistSig)) {
                *result = 8;
                return;
            }
        }
        {
            using _t = void (TracksDataEntry::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&TracksDataEntry::loadQueuedTracksSig)) {
                *result = 9;
                return;
            }
        }
        {
            using _t = void (TracksDataEntry::*)(int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&TracksDataEntry::addTrackToQueSig)) {
                *result = 10;
                return;
            }
        }
    }
#ifndef QT_NO_PROPERTIES
    else if (_c == QMetaObject::ReadProperty) {
        auto *_t = static_cast<TracksDataEntry *>(_o);
        Q_UNUSED(_t)
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast< int*>(_v) = _t->getCount(); break;
        case 1: *reinterpret_cast< bool*>(_v) = _t->getDoneFetching(); break;
        case 2: *reinterpret_cast< bool*>(_v) = _t->getIsLoading(); break;
        case 3: *reinterpret_cast< int*>(_v) = _t->getActiveTrackId(); break;
        case 4: *reinterpret_cast< int*>(_v) = _t->getActiveIndex(); break;
        default: break;
        }
    } else if (_c == QMetaObject::WriteProperty) {
        auto *_t = static_cast<TracksDataEntry *>(_o);
        Q_UNUSED(_t)
        void *_v = _a[0];
        switch (_id) {
        case 0: _t->setCount(*reinterpret_cast< int*>(_v)); break;
        case 1: _t->setDoneFetching(*reinterpret_cast< bool*>(_v)); break;
        case 2: _t->setIsLoading(*reinterpret_cast< bool*>(_v)); break;
        case 3: _t->setActiveTrackId(*reinterpret_cast< int*>(_v)); break;
        case 4: _t->setActiveIndex(*reinterpret_cast< int*>(_v)); break;
        default: break;
        }
    } else if (_c == QMetaObject::ResetProperty) {
        TracksDataEntry *_t = static_cast<TracksDataEntry *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->resetCount(); break;
        default: break;
        }
    }
#endif // QT_NO_PROPERTIES
}

QT_INIT_METAOBJECT const QMetaObject TracksDataEntry::staticMetaObject = { {
    QMetaObject::SuperData::link<QAbstractListModel::staticMetaObject>(),
    qt_meta_stringdata_TracksDataEntry.data,
    qt_meta_data_TracksDataEntry,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *TracksDataEntry::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *TracksDataEntry::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_TracksDataEntry.stringdata0))
        return static_cast<void*>(this);
    return QAbstractListModel::qt_metacast(_clname);
}

int TracksDataEntry::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QAbstractListModel::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 32)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 32;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 32)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 32;
    }
#ifndef QT_NO_PROPERTIES
    else if (_c == QMetaObject::ReadProperty || _c == QMetaObject::WriteProperty
            || _c == QMetaObject::ResetProperty || _c == QMetaObject::RegisterPropertyMetaType) {
        qt_static_metacall(this, _c, _id, _a);
        _id -= 5;
    } else if (_c == QMetaObject::QueryPropertyDesignable) {
        _id -= 5;
    } else if (_c == QMetaObject::QueryPropertyScriptable) {
        _id -= 5;
    } else if (_c == QMetaObject::QueryPropertyStored) {
        _id -= 5;
    } else if (_c == QMetaObject::QueryPropertyEditable) {
        _id -= 5;
    } else if (_c == QMetaObject::QueryPropertyUser) {
        _id -= 5;
    }
#endif // QT_NO_PROPERTIES
    return _id;
}

// SIGNAL 0
void TracksDataEntry::countChanged(int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void TracksDataEntry::doneFetchingChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}

// SIGNAL 2
void TracksDataEntry::isLoadingChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 2, nullptr);
}

// SIGNAL 3
void TracksDataEntry::activeIndexChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 3, nullptr);
}

// SIGNAL 4
void TracksDataEntry::activeTrackIdChanged(int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 4, _a);
}

// SIGNAL 5
void TracksDataEntry::fetchTracks(int _t1, int _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))) };
    QMetaObject::activate(this, &staticMetaObject, 5, _a);
}

// SIGNAL 6
void TracksDataEntry::fetchPlaylistTracks(int _t1, int _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))) };
    QMetaObject::activate(this, &staticMetaObject, 6, _a);
}

// SIGNAL 7
void TracksDataEntry::fetchRecentlyPlayedTracks()
{
    QMetaObject::activate(this, &staticMetaObject, 7, nullptr);
}

// SIGNAL 8
void TracksDataEntry::addTrackToPlaylistSig(int _t1, int _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))) };
    QMetaObject::activate(this, &staticMetaObject, 8, _a);
}

// SIGNAL 9
void TracksDataEntry::loadQueuedTracksSig()
{
    QMetaObject::activate(this, &staticMetaObject, 9, nullptr);
}

// SIGNAL 10
void TracksDataEntry::addTrackToQueSig(int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 10, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
