#ifndef PLAYLISTADAPTER_H
#define PLAYLISTADAPTER_H

#include <QAbstractListModel>
#include <QList>
#include <QObject>
#include "src/models/jmodels.h"
#include "src/models/jrole.h"
#include "src/workers/mainworker.h"

class PlaylistAdapter : public QAbstractListModel
{
    Q_OBJECT
    Q_PROPERTY(bool isLoading READ getIsLoading WRITE setIsLoading NOTIFY isLoadingChanged)
     Q_PROPERTY(int count READ getCount WRITE setCount NOTIFY countChanged)
public:
    explicit PlaylistAdapter(QObject *parent = nullptr);



    // QAbstractItemModel interface
public:
    virtual int rowCount(const QModelIndex &parent) const override;
    virtual QVariant data(const QModelIndex &index, int role) const override;
    virtual QHash<int, QByteArray> roleNames() const override;

    bool getIsLoading() const;
    void setIsLoading(bool newIsLoading);

    int getCount() const;
    void setCount(int newCount);

public slots:
    void loadPlaylists(bool isHome=false,bool folders=false);
    void loadAiPlaylists();

    void addPlaylist(QString title);

signals:
    void isLoadingChanged();

    void countChanged();

private:

    QList<JPlaylist> playlists;
    JRole &mRoles=JRole::getInstance();
    MainWorker &worker=MainWorker::getInstance();

private:
    void add(JPlaylist p,int index);

private:
    bool isLoading=false;
    int count=0;


};

#endif // PLAYLISTADAPTER_H
