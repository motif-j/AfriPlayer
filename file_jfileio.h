#ifndef JFILEIO_H
#define JFILEIO_H

#include <QObject>
#include <file_fileworker.h>
#include <QThread>

class JFileIO : public QObject
{
    QThread fileIoThread;
    Q_OBJECT
public:

    static JFileIO &getInstance(){
        static JFileIO fileIo;

        return fileIo;

    }

    ~JFileIO(){
        fileIoThread.quit();
        fileIoThread.wait();

    }

public:
    void queryDir(){
        QDir dir("G:\\CIERA\\MotifFiles\\Muhimu\\Muzik");
        emit queryAudioFilesInDir(dir);
    }
private:

    JFileIO(QObject *parent = nullptr){
        Q_UNUSED(parent)

        worker->moveToThread(&fileIoThread);

        connect(&fileIoThread,&QThread::finished,worker,&QObject::deleteLater);
        connect(worker,&FilWorker::queryAllDirCompleted,this,&JFileIO::onFileQueryCompleted);
        connect(this,&JFileIO::queryAudioFilesInDir,worker,&FilWorker::queryAllDirectories);

        fileIoThread.start();



    }

private:

    FilWorker *worker=new FilWorker;

public slots:
    void  onFileQueryCompleted();

signals:

    void  queryAudioFilesInDir(QDir dir);
};

#endif // JFILEIO_H
