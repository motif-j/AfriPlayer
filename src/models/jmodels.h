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


    int trackId=0;
    int artistId=0;
    int albumId=0;
    int releaseYear=0;

    long long dateAdded=0;
    long long duration=0;

    bool isFavorite=false;
    bool hasPlayed=false;
    bool isPlaying=false;


    QString trackName="";
    QString fileUrl="";
    QString albumName="";
    QString artistName="";
    QString colors="";



    bool operator ==(const JTrack &a) const{

        return a.trackId==this->trackId;
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
