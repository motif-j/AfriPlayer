#ifndef JMUSICCONTROLLERINTERFACE_H
#define JMUSICCONTROLLERINTERFACE_H

#include <QObject>
#include <QtQml/qqml.h>
#include "jmusiccontroller.h"

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

        //connect directly to the signals of the main controller
        connect(&musicController,&JMusicController::trackFetched,this,&JMusicControllerInterface::trackFetchedFromRepo);

        connect(&musicController,&JMusicController::playingTrackFetched,this,&JMusicControllerInterface::playingTrackFetched);

        Q_PROPERTY(int activeTrackId READ getActiveTrackId WRITE setActiveTrackId NOTIFY activeTrackIdChanged)
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

    //These signals directly communicate with the QML file
signals:
    void trackFetchedFromRepo(QVariantMap trackMap);
    void playingTrackFetched(QVariantMap trackMap);

    void activeTrackIdChanged();

private:
    JMusicController &musicController=JMusicController::getInstance();
    int activeTrackId;


};


#endif // JMUSICCONTROLLERINTERFACE_H
