#ifndef JROLE_H
#define JROLE_H
#include <QObject>
#include <QByteArray>
#include <QHash>


class JRole
{

public:

    static JRole &getInstance(){
        static JRole instance;

        return instance;

    }
    enum TrackRole{

        ROLE_TRACKNAME=Qt::UserRole,
        ROLE_TRACKID=Qt::UserRole+2,
        ROLE_ARTISTID=Qt::UserRole+4,
        ROLE_ALBUMID=Qt::UserRole+6,
        ROLE_DURATION=Qt::UserRole+8,
        ROLE_ARTISTNAME=Qt::UserRole+10,
        ROLE_ALBUMNAME=Qt::UserRole+12,
        ROLE_FILEURL=Qt::UserRole+14,
        ROLE_PLAYLISTNAME=Qt::UserRole+16,
        ROLE_PLAYLISTID=Qt::UserRole+18,
        ROLE_ISFAVORITE=Qt::UserRole+20,
        ROLE_ISPLAYING=Qt::UserRole+22,
        ROLE_COLORS=Qt::UserRole+24


    };


    const QHash<int, QByteArray> &roles() const;

private:
    JRole() {

        mRoles[ROLE_TRACKNAME]="trackName";
        mRoles[ROLE_TRACKID]="trackId";
        mRoles[ROLE_ALBUMID]="albumId";
        mRoles[ROLE_DURATION]="duration";
        mRoles[ROLE_ARTISTNAME]="artistName";
        mRoles[ROLE_ARTISTID]="artistId";
        mRoles[ROLE_ALBUMNAME]="albumName";
        mRoles[ROLE_FILEURL]="fileUrl";
        mRoles[ROLE_PLAYLISTNAME]="playlistName";
        mRoles[ROLE_PLAYLISTID]="playlistId";
        mRoles[ROLE_ISFAVORITE]="isFavorite";
        mRoles[ROLE_ISPLAYING]="isPlaying";
        mRoles[ROLE_COLORS]="colors";
    }

    QHash<int,QByteArray> mRoles;
};

inline const QHash<int, QByteArray> &JRole::roles() const
{
    return mRoles;
}


#endif // JROLE_H
