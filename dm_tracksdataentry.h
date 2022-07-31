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
#include "jw_tracksworker.h"



class TracksDataEntry : public QAbstractListModel
{

    Q_OBJECT
    Q_PROPERTY(int count READ getCount WRITE setCount RESET resetCount NOTIFY countChanged)
    Q_PROPERTY(bool doneFetching READ getDoneFetching WRITE setDoneFetching NOTIFY doneFetchingChanged)


    QThread databaseThread;

public:
    ~TracksDataEntry(){

        databaseThread.quit();
        databaseThread.wait();
    }

    explicit TracksDataEntry(QObject *parent = nullptr){
        Q_UNUSED(parent);

        JTracksWorker *dbWorker=new JTracksWorker;

        dbWorker->moveToThread(&databaseThread);

        connect(&databaseThread,&QThread::finished,dbWorker,&QObject::deleteLater);
        connect(dbWorker,&JTracksWorker::tracksFetched,this,&TracksDataEntry::handleFetchedTracks);
        connect(this,&TracksDataEntry::fetchTracks,dbWorker,&JTracksWorker::fetchTracks);

        databaseThread.setObjectName("Database Thread");


        databaseThread.start();



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


    //class slots exposed to other classes
public slots:
    void handleFetchedTracks(QList<JTrack> *tracks);

signals:
    void countChanged(int count);

    void doneFetchingChanged();

    void fetchTracks(int lastId,int limit);



private:
    bool doneFetching=false;

    QList<JTrack> m_data;
    int count=0;
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
};

#endif // TRACKSDATAENTRY_H
