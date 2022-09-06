#ifndef PTRACKSADAPTER_H
#define PTRACKSADAPTER_H

#include <QObject>
#include <src/adapters/tracksadpater.h>
#include <src/ai/aiplaylistmanager.h>

class PTracksAdapter : public AbstractTracksAdapter
{
    Q_OBJECT
    Q_PROPERTY(bool isUserPlaylist READ getIsUserPlaylist WRITE setIsUserPlaylist NOTIFY isUserPlaylistChanged)

public:
    explicit PTracksAdapter(QObject *parent = nullptr);


    bool getIsUserPlaylist() const;
    void setIsUserPlaylist(bool newIsUserPlaylist);

private:
    AiPlaylistManager &aiManager=AiPlaylistManager::getInstance();
private:
    int playlistId;
    bool isUserPlaylist=false;


public slots:
    void loadTracks(int playlistId,int refresh=0);
    void loadAiTracks(int playlistId);
    void addTracksToQueue(bool append);



    //listeners


    // AbstractTracksAdapter interface
signals:
    void isUserPlaylistChanged();

private slots:
    virtual void onTrackRemovedFromPlaylist(JTrack track,bool isFavorite) override;
};

#endif // PTRACKSADAPTER_H
