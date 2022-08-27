#ifndef JPLAYLISTCONTROLLER_H
#define JPLAYLISTCONTROLLER_H

#include <QObject>
#include <QString>

#include <QList>
#include <src/models/jmodels.h>
#include <src/utils/jsettings.h>
#include <src/workers/mainworker.h>
#include <src/engine/audioengine.h>


class JPlaylistController : public QObject
{
    Q_OBJECT
private:
    JPlaylistController(QObject *parent = nullptr){
        Q_UNUSED(parent)

        await(worker.getTrack(settings.getPlayingTrackId()),this,[this](JTrack res){

            if(res.trackId>0){

                addTrackToQueue(res,false);


            }

          dynamicLoadQueueTracks();

        });


    }
public:
    static JPlaylistController &getInstance(){
        static JPlaylistController instance;
        return instance;

    }

public:
    QList<JTrack> *getPlaylist();
    void loadPlayingTrackToQueuePlaylist(JTrack track);
    void addTrackToQueue(JTrack track,bool updateInDb=false);
    JTrack getNextTrack();
    JTrack getPreviousTrack();
    void addPlaylistToQueue(int playlistId,bool shuffle);
    void addTrackToPlaylist(int trackId,int playlistId);

    //playback functions
private:
    void playFromUrl(JTrack track);
    void dynamicLoadQueueTracks();
    void toggleTrackAsPlayed(int trackId);


    //getters and setters
public:
    int getPlayingIndex() const;
    void setPlayingIndex(int newPlayingIndex);

    bool getIsLoading() const;
    void setIsLoading(bool newIsLoading);

private:
    QList<JTrack> *playlist=new QList<JTrack>();
    JSettings &settings=JSettings::getInstance();
    MainWorker &worker=MainWorker::getInstance();
    AudioEngine &engine=AudioEngine::getInstance();

    int indexFromPlaylist(int playingTrackId);
    int playingIndex;
    bool isLoading=false;

signals:
    void notifyTrackInserted(JTrack track, int index,int lastIndex);
    void notifyTrackSelected(JTrack,int index,int lastIndex);
    void trackPlaybackStarted(JTrack track);
    void notifyAmBusy(bool);
    void notifyTrackAddedToPlaylist(JTrack track);

};

#endif // JPLAYLISTCONTROLLER_H
