#ifndef TRACKSDATAENTRY_H
#define TRACKSDATAENTRY_H

#include <QAbstractListModel>
#include <QObject>
#include <QString>
#include <QList>
#include<QtGui>
#include "jmodels.h"
#include <QVariant>
#include <QDebug>
#include <QVariantMap>
#include "jrole.h"
#include "jmusiccontroller.h"


extern QString formatTrackTime(QTime);

class TracksDataEntry : public QAbstractListModel
{

    Q_OBJECT
    Q_PROPERTY(int count READ getCount WRITE setCount RESET resetCount NOTIFY countChanged)
    Q_PROPERTY(bool doneFetching READ getDoneFetching WRITE setDoneFetching NOTIFY doneFetchingChanged)
    Q_PROPERTY(bool isLoading READ getIsLoading WRITE setIsLoading NOTIFY isLoadingChanged)
    Q_PROPERTY(int activeTrackId READ getActiveTrackId WRITE setActiveTrackId NOTIFY activeTrackIdChanged)
    Q_PROPERTY(int activeIndex READ getActiveIndex WRITE setActiveIndex NOTIFY activeIndexChanged)

public:
    ~TracksDataEntry(){

    }

    explicit TracksDataEntry(QObject *parent = nullptr){
        Q_UNUSED(parent);

        qDebug()<<"CREATED DATA ENTRY";


        clearPlaylist();
        //  connect(&databaseThread,&QThread::finished,dbWorker,&QObject::deleteLater);
        connect(&mController,&JMusicController::tracksLoaded,this,&TracksDataEntry::handleFetchedTracks);
        connect(this,&TracksDataEntry::fetchTracks,&mController,&JMusicController::loadTracks);


        connect(this,&TracksDataEntry::fetchPlaylistTracks,&mController,&JMusicController::loadPlaylistTrack);
        // connect(&mController,&JMusicController::playlistTracksFetched,this,&TracksDataEntry::handleFetchedTracks);

        connect(&mController,&JMusicController::playlistTracksLoaded,this,&TracksDataEntry::handleFetchedPlaylstTracks);
        connect(&mController,&JMusicController::activeTrackIdChanged,this,&TracksDataEntry::handleActiveTrackIdChanged);

        connect(this,&TracksDataEntry::fetchRecentlyPlayedTracks,&mController,&JMusicController::loadRecentlyPlayedTracks);
        connect(&mController,&JMusicController::recentlyPlayedTracksFetched,this,&TracksDataEntry::handleRecentlyFetchedTracks);
    }


    // QAbstractItemModel interface
public:

    virtual int rowCount(const QModelIndex &parent) const override;
    virtual QVariant data(const QModelIndex &index, int role) const override;


    int getCount() const;
    void setCount(int newCount);
    void resetCount();

    void reloadRecentlyPlayedTracks();
    //Qml slots
public slots:

    void loadMoreTracks();
    void loadPlaylistTracks(int playlistId,int refreshCode);
    void loadRecentlyPlayedTracks();
    void clearPlaylist();

    void addTrackToRecentlyPlayed(int trackId);

    void incrementIndex();
    void decrementIndex();

    //class slots exposed to other classes
public slots:
    void handleFetchedTracks(QList<JTrack> *tracks);
    void handleFetchedPlaylstTracks(QList<JTrack>*);
    void handleActiveTrackIdChanged(int newId);
    void handleRecentlyFetchedTracks(QList<JTrack>*);

    //QML signals
signals:
    void countChanged(int count);

    void doneFetchingChanged();

    //QML
    void isLoadingChanged();

    void activeIndexChanged();

    void activeTrackIdChanged();

    //Controller Signals
signals:

    void fetchTracks(int lastId,int limit);

    void fetchPlaylistTracks(int playlistId,int refreshCode);
    void fetchRecentlyPlayedTracks();




private:
    int count=0;
    bool isLoading=false;
    int playlistId=0;
    int activeIndex=-1;
    int activeTrackId;

private:
    JMusicController &mController=JMusicController::getInstance();

    bool doneFetching=false;

    QList<JTrack> m_data;
    const int limit=20;

    JRole &jroles=JRole::getInstance();



    //functions
private:
    void loadTracks();
    void addData(QList<JTrack>*);


    // QAbstractItemModel interface


public:
    virtual QHash<int, QByteArray> roleNames() const override;
    bool getDoneFetching() const;
    void setDoneFetching(bool newDoneFetching);
    bool getIsLoading() const;
    void setIsLoading(bool newIsLoading);
    int getActiveTrackId() const;
    void setActiveTrackId(int newActiveTrackId);
    int getActiveIndex() const;
    void setActiveIndex(int newActiveIndex);
};

#endif // TRACKSDATAENTRY_H
