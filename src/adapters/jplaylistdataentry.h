#ifndef JPLAYLISTDATAENTRY_H
#define JPLAYLISTDATAENTRY_H

#include <QAbstractListModel>
#include <QObject>
#include<QHash>
#include<QByteArray>
#include<QList>
#include<QDebug>
#include "../models/jrole.h"
#include "../models/jmodels.h"
#include "../controllers/jmusiccontroller.h"

class JPlaylistDataEntry : public QAbstractListModel
{
    Q_OBJECT
    Q_PROPERTY(int count READ getCount WRITE setCount NOTIFY countChanged)
public:
    explicit JPlaylistDataEntry(QObject *parent = nullptr);


    // QAbstractItemModel interface
public:
    virtual int rowCount(const QModelIndex &parent) const override;
    virtual QVariant data(const QModelIndex &index, int role) const override;
    virtual QHash<int, QByteArray> roleNames() const override;

    //slots that interact with the qml
    int getCount() const;
    void setCount(int newCount);

public slots:

    void loadHomePlaylists(){
        emit fetchHomePlaylistsFromRepo();
    }

    //slots that interact with the controller
public slots:
 void handleHomePlaylistsFetched(QList<JPlaylist> *result);


 //signal that interact with the controller
signals:
 void fetchHomePlaylistsFromRepo();


 //signals that interact with qml
signals:
 void countChanged();

private:
    JRole &mRoles=JRole::getInstance();
    JMusicController &mController=JMusicController::getInstance();
    QList<JPlaylist> playlists;
    int count=0;


    //functions
private:
    //void add

};

#endif // JPLAYLISTDATAENTRY_H
