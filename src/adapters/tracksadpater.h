#ifndef TRACKSADPATER_H
#define TRACKSADPATER_H

#include <QAbstractListModel>
#include <QObject>
#include "src/models/jrole.h"
#include "src/models/jmodels.h"
#include <QList>
#include <QTime>
#include <QDebug>
#include <QFutureWatcher>
#include "src/workers/mainworker.h"
#include <src/controllers/jplaylistcontroller.h>

extern QString formatTrackTime(QTime);

class AbstractTracksAdapter : public QAbstractListModel
{
    Q_OBJECT
    Q_PROPERTY(bool isLoading READ getIsLoading WRITE setIsLoading NOTIFY isLoadingChanged)
    Q_PROPERTY(int count READ getCount WRITE setCount NOTIFY countChanged)

public:
    AbstractTracksAdapter(QObject *parent = nullptr){
        Q_UNUSED(parent)

        connect(&playlistController,&JPlaylistController::notifyAmBusy,this,&AbstractTracksAdapter::onBusyChanged);

        connect(&playlistController,&JPlaylistController::notifyTrackAddedToPlaylist,this,&AbstractTracksAdapter::onTrackAddedToPlaylist);


    }

    ~AbstractTracksAdapter();

    //properties
protected:
    QList<JTrack> tracks;
    bool isLoading=false;
    MainWorker &woker=MainWorker::getInstance();
    JPlaylistController &playlistController=JPlaylistController::getInstance();


    //functions
protected:
    void add(JTrack track,int index);
    void update(JTrack track,int index);
    int getIndexFromId(int trackId);

private:
    int count=0;
    JRole &roles=JRole::getInstance();
private:

    // QAbstractItemModel interface

public:
    virtual int rowCount(const QModelIndex &parent) const override;
    virtual QVariant data(const QModelIndex &index, int role) const override;
    virtual QHash<int, QByteArray> roleNames() const override;

    //Adapter functions
public:
    bool getIsLoading() const;
    void setIsLoading(bool newIsLoading);

    int getCount() const;
    void setCount(int newCount);

public slots:

    void clearTracks();

    //listeners
private slots:
    void onBusyChanged(bool loading);
    void onTrackAddedToPlaylist(JTrack track);
signals:
    void isLoadingChanged();
    void countChanged();
};

#endif // TRACKSADPATER_H
