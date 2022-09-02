import QtQuick 2.9

Item {


    signal activeTrackIdChanged(int trackId)
    signal trackFetched(var trackMap)
    signal trackPlayed(int trackId)

    signal playTrack(int trackId);
    signal playStatChanged;


}
