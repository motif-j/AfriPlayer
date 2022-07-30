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
#include "db_jmalkiadbinterface.h"


class TracksDataEntry : public QAbstractListModel
{
    Q_OBJECT
    Q_PROPERTY(int count READ getCount WRITE setCount RESET resetCount NOTIFY countChanged)
    Q_PROPERTY(bool doneFetching READ getDoneFetching WRITE setDoneFetching NOTIFY doneFetchingChanged)

public:
    explicit TracksDataEntry(QObject *parent = nullptr){
        Q_UNUSED(parent);

        this->loadTracks();

    }


    // QAbstractItemModel interface
public:

    virtual int rowCount(const QModelIndex &parent) const override;
    virtual QVariant data(const QModelIndex &index, int role) const override;


    int getCount() const;
    void setCount(int newCount);
    void resetCount();

public slots:
    // void add(int index,const QString &color);
    void add(const JTrack &track);
    void loadMoreTracks();


    //fields
signals:
    void countChanged(int count);

    void doneFetchingChanged();

private:
    bool doneFetching;

    QList<JTrack> m_data;
    int count=0;
    const int limit=20;

    JRole &jroles=JRole::getInstance();
    JMalkiaDbInterface &db=JMalkiaDbInterface::getInstace();


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
