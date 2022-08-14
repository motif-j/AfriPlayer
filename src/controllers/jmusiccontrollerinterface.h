#ifndef JMUSICCONTROLLERINTERFACE_H
#define JMUSICCONTROLLERINTERFACE_H

#include <QObject>
#include <QtQml/qqml.h>
#include "jmusiccontroller.h"
#include "../fileio/file_jfileio.h"


/*
*Having this class feels like redudancy
*However I want the music controller to be a single instance in the entire project.
*To achieve that I have opted for an interface class which will be called from
*the QML and instantiate only a single instance of the music controller.
*The Music controller will be in charge of controlling staffs like current playing track, playlist
*This interface is mainly applicable for the whole QML app
*/

class JMusicControllerInterface : public QObject
{
    Q_OBJECT
    QML_ELEMENT
    QML_SINGLETON


public:
    JMusicControllerInterface(QObject *parent = nullptr){

        Q_UNUSED(parent)
        qDebug()<<"INITIALIZING INTERFACE";

        JFileIO &fileIo=JFileIO::getInstance();
        //fileIo.queryDir();



        // qDebug()<<" PATH IS "<<path;
        //connect directly to the signals of the main controller
        connect(&musicController,&JMusicController::trackFetched,this,&JMusicControllerInterface::trackFetchedFromRepo);

        connect(&musicController,&JMusicController::playingTrackFetched,this,&JMusicControllerInterface::playingTrackFetched);


        Q_PROPERTY(bool shuffle READ getShuffle WRITE setShuffle NOTIFY shuffleChanged)
        Q_PROPERTY(int activeTrackId READ getActiveTrackId WRITE setActiveTrackId NOTIFY activeTrackIdChanged)

        Q_PROPERTY(bool dynamicMode READ getDynamicMode WRITE setDynamicMode NOTIFY dynamicModeChanged)


        QSettings settings("AfrikTek","Qplayer");

        bool shuffle=settings.value("shuffle",false).toBool();

        setShuffle(shuffle);
    }

    ~JMusicControllerInterface() {

        qDebug()<<"DESTROYING INTERFACE";
    }
    //music controller slots
    int getActiveTrackId() const{
        return activeTrackId;
    }
    void setActiveTrackId(int newActiveTrackId){
        if (activeTrackId == newActiveTrackId)
            return;
        activeTrackId = newActiveTrackId;
        emit activeTrackIdChanged();
    }

    bool getShuffle() const
    {
        return shuffle;
    }

    void setShuffle(bool newShuffle)
    {
        if (shuffle == newShuffle)
            return;
        shuffle = newShuffle;
        emit shuffleChanged();
    }

    //  bool getShuffle() const;
    //  void setShuffle(bool newShuffle);

    bool getDynamicMode() const;
    void setDynamicMode(bool newDynamicMode);


public slots:
    void  handleFetchedTrack(QVariantMap trackMap){

        emit trackFetchedFromRepo(trackMap);
    }
    void handleFetchedPlayingTrack(QVariantMap map){
        emit playingTrackFetched(map);
    }


    //qml interface slots
public slots:

    void getTrack(int trackId){
        musicController.getTrack(trackId);

    }

    void getPlayingTrack(int trackId){

        musicController.getPlayingTrack(trackId);
    }

    void trackClicked(int trackId){
        setActiveTrackId(trackId);
        musicController.setActiveTrackId(trackId);
    }

    void addTrackToRecentlyPlayed(int trackId){
        musicController.addTrackToRecentsPlaylist(trackId);
    }

    void addTrackToPlaylist(int trackId,int playlistId){
        musicController.addTrackToPlaylist(trackId,playlistId);
    }
    void addTrackToQue(int trackId){
        musicController.addTrackToQueue(trackId);
    }

    void addPlaylistToQueue(int playlistId,bool shuffle){

        QSettings settings("AfrikTek","Qplayer");
        settings.setValue("shuffle",shuffle);

        setShuffle(shuffle);


        musicController.addPlaylistToQueue(playlistId,false);
    }

    void toggleShuffle()
    {
        QSettings settings("AfrikTek","Qplayer");
        bool shuffle=settings.value("shuffle",false).toBool();

        bool newShuffleMode=!shuffle;

        settings.setValue("shuffle",newShuffleMode);

        setShuffle(newShuffleMode);

    }


    //These signals directly communicate with the QML file
signals:
    void trackFetchedFromRepo(QVariantMap trackMap);
    void playingTrackFetched(QVariantMap trackMap);

    void activeTrackIdChanged();



    void shuffleChanged();

    void dynamicModeChanged();

    void busyChanged();

private:
    JMusicController &musicController=JMusicController::getInstance();
    int activeTrackId;
    bool shuffle;
    bool dynamicMode;





};

inline bool JMusicControllerInterface::getDynamicMode() const
{
    return dynamicMode;
}

inline void JMusicControllerInterface::setDynamicMode(bool newDynamicMode)
{
    if (dynamicMode == newDynamicMode)
        return;
    dynamicMode = newDynamicMode;
    emit dynamicModeChanged();
}




#endif // JMUSICCONTROLLERINTERFACE_H
