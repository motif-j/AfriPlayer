#ifndef PTRACKSADAPTER_H
#define PTRACKSADAPTER_H

#include <QObject>
#include <src/adapters/tracksadpater.h>

class PTracksAdapter : public AbstractTracksAdapter
{
    Q_OBJECT
public:
    explicit PTracksAdapter(QObject *parent = nullptr);

private:
    int playlistId;

public slots:
    void loadTracks(int playlistId,int refresh=0);


    //listeners


    // AbstractTracksAdapter interface
private slots:
    virtual void onTrackRemovedFromPlaylist(JTrack track,bool isFavorite) override;
};

#endif // PTRACKSADAPTER_H
