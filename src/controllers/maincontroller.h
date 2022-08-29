#ifndef MAINCONTROLLER_H
#define MAINCONTROLLER_H

#include <QList>
#include <QObject>
#include "src/models/jmodels.h"
#include "src/workers/mainworker.h"
#include "src/engine/audioengine.h"
#include "src/utils/jsettings.h"
#include "jplaylistcontroller.h"
#include "src/fileio/jfileworker.h"
#include "src/enums/jenums.h"

class MainController : public QObject
{
    Q_OBJECT
    Q_PROPERTY(int playingTrackId READ getPlayingTrackId WRITE setPlayingTrackId NOTIFY playingTrackIdChanged)
    Q_PROPERTY(bool shuffle READ getShuffle WRITE setShuffle NOTIFY shuffleChanged)
    Q_PROPERTY(bool isQuering READ getIsQuering WRITE setIsQuering NOTIFY isQueringChanged)
     Q_PROPERTY(int repeateMode READ getRepeateMode WRITE setRepeateMode NOTIFY repeateModeChanged)



public:
    explicit MainController(QObject *parent = nullptr);



    int getPlayingTrackId() const;
    void setPlayingTrackId(int newPlayingTrackId);

    bool getShuffle() const;
    void setShuffle(bool newShuffle);

    bool getIsQuering() const;
    void setIsQuering(bool newIsQuering);


    int getRepeateMode() const;
    void setRepeateMode(int newRepeateMode);

public slots:
    void loadTrackToEngine(int trackId);
    void addTrackToPlayingQue(int trackId);
    void addPlaylistToQueue(int playlistId);
    void addTrackToPlaylist(int trackId,int playlistId);

    //utils
public slots:
    void toggleShuffle();
    void queryAudioFiles();
    void toggleRepeateMode();

    //playback
public slots:
    void playNext();
    void playPrevious();

private:
    MainWorker &worker=MainWorker::getInstance();
    JFileWorker &fileWorker=JFileWorker::getInstance();

    JSettings &settings=JSettings::getInstance();
    JPlaylistController &playlistController=JPlaylistController::getInstance();
    QList<JTrack> playlist;


private:


    //QML properties
private:
    int playingTrackId;
    bool shuffle=false;
    bool isQuering=false;
   int repeateMode=0;






signals:

    void playingTrackIdChanged();

    void shuffleChanged();
    void isQueringChanged();

    void repeateModeChanged();
};



#endif // MAINCONTROLLER_H
