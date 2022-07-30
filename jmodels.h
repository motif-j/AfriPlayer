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

};

#endif // JMODELS_H
