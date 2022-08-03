#ifndef JMODELS_H
#define JMODELS_H

#include <QString>
#include "jrole.h"

//struct JTrack{
//    int trackId;
//    int artistId;
//    int albumId;
//    long duration;

//    QString trackName;
//    QString fileUrl;
//};

struct JTrack{


    int trackId;
    int artistId;
    int albumId;
    long long duration;

    QString trackName;
    QString fileUrl;
    QString albumName;
    QString artistName;

    bool operator ==(JTrack a){

        return a.trackId==this->trackId;
    }
    void x(){

    }

};

struct JPlaylist{
    int playlistId;
    QString playlistTitle;
    QString colors;

    bool operator ==(JPlaylist other){
        return other.playlistId==this->playlistId;
    }

};

#endif // JMODELS_H
