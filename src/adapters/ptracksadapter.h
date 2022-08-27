#ifndef PTRACKSADAPTER_H
#define PTRACKSADAPTER_H

#include <QObject>
#include <src/adapters/tracksadpater.h>

class PTracksAdapter : public AbstractTracksAdapter
{
    Q_OBJECT
public:
    explicit PTracksAdapter(QObject *parent = nullptr);

public slots:
      void loadTracks(int playlistId,int refresh=0);
};

#endif // PTRACKSADAPTER_H
