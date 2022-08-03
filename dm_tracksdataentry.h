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

public:
    ~TracksDataEntry(){

    }

    explicit TracksDataEntry(QObject *parent = nullptr){
        Q_UNUSED(parent);



        //  connect(&databaseThread,&QThread::finished,dbWorker,&QObject::deleteLater);
        connect(&mController,&JMusicController::tracksLoaded,this,&TracksDataEntry::handleFetchedTracks);
        connect(this,&TracksDataEntry::fetchTracks,&mController,&JMusicController::loadTracks);

        connect(this,&TracksDataEntry::fetchPlaylistTracks,&mController,&JMusicController::loadPlaylistTrack);
        // connect(&mController,&JMusicController::playlistTracksFetched,this,&TracksDataEntry::handleFetchedTracks);


    }


    // QAbstractItemModel interface
public:

    virtual int rowCount(const QModelIndex &parent) const override;
    virtual QVariant data(const QModelIndex &index, int role) const override;


    int getCount() const;
    void setCount(int newCount);
    void resetCount();

    //Qml slots
public slots:

    void loadMoreTracks();
    void loadPlaylistTracks(int playlistId);
    void clearPlaylist();



    //class slots exposed to other classes
public slots:
    void handleFetchedTracks(QList<JTrack> *tracks);


    //QML signals
signals:
    void countChanged(int count);

    void doneFetchingChanged();



    //Controller Signals
signals:

    void fetchTracks(int lastId,int limit);

    void fetchPlaylistTracks(int playlistId);


    //QML
    void isLoadingChanged();

private:
    int count=0;
    bool isLoading=false;

private:
    JMusicController &mController=JMusicController::getInstance();

    bool doneFetching=false;

    QList<JTrack> m_data;
    const int limit=20;

    JRole &jroles=JRole::getInstance();



    //functions
private:
    void loadTracks();


    // QAbstractItemModel interface




public:
    virtual QHash<int, QByteArray> roleNames() const override;
    bool getDoneFetching() const;
    void setDoneFetching(bool newDoneFetching);
    bool getIsLoading() const;
    void setIsLoading(bool newIsLoading);
};

#endif // TRACKSDATAENTRY_H
