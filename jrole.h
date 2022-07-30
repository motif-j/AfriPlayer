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
    }

    QHash<int,QByteArray> mRoles;
};

inline const QHash<int, QByteArray> &JRole::roles() const
{
    return mRoles;
}


#endif // JROLE_H
