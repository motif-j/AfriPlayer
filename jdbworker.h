#ifndef JDBWORKER_H
#define JDBWORKER_H

#include <QObject>
#include<QString>
#include<QDebug>

class JDbWorker : public QObject
{
    Q_OBJECT
public:
    explicit JDbWorker(QObject *parent = nullptr){
        Q_UNUSED(parent);
    }


public slots:
    void doWork(const QString &param){

        qDebug()<<"Operatiing on "<<param;
        QString result="LAAAAAAAAAAAAAAA";

        emit resultReady(result);

    }
    void operate(){
         qDebug()<<"Operatiing on ";
    }


signals:
    void resultReady(QString &result);

};

#endif // JDBWORKER_H
