#include "mythread.h"

#include <QDebug>
#include "db_jmalkiadbinterface.h"

MyThread::MyThread(QObject *parent)
    : QThread{parent}
{

}

void MyThread::run()
{
    //JMalkiaDb dn=JMalkiaDb::newInstance();
    JMalkiaDbInterface &db=JMalkiaDbInterface::getInstace();


  //  dn.getAllTracks();

}
