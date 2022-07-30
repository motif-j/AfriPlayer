#include "mythread.h"

#include <QDebug>
#include "db_jmalkiadbinterface.h"

MyThread::MyThread(QObject *parent)
    : QThread{parent}
{

}

void MyThread::run()
{
    qDebug()<<"From Thread";
    JMalkiaDbInterface &db=JMalkiaDbInterface::getInstace();

  // auto c= db.getTracks();
  // for(auto v : *c){
   //    qDebug()<<v.trackName;
   //}

  // db.massInsert();

}
