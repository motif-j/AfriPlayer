#ifndef JW_TRACKSWORKER_H
#define JW_TRACKSWORKER_H

#include<QObject>
#include "db_jmalkiadbinterface.h"

class JTracksWorker : public QObject
{
    JMalkiaDbInterface &db=JMalkiaDbInterface::getInstace();

    Q_OBJECT
public:
    explicit  JTracksWorker(QObject *parent=nullptr) {
        Q_UNUSED(parent)
    }

    virtual ~JTracksWorker() {

    }

public slots:
    void fetchTracks(int lastId,int limit){

        qDebug()<<"Executing in Thread 2";
        auto tracks=db.getTracks(lastId,limit);


        emit tracksFetched(tracks);

    }

signals:

    void tracksFetched(QList<JTrack> *tracks);

};
#endif // JW_TRACKSWORKER_H
