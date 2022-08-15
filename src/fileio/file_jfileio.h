#ifndef JFILEIO_H
#define JFILEIO_H

#include <QObject>
#include "../fileio/file_fileworker.h"
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
    void queryAudioFilesInDir(){
      //  QDir dir("G:\\CIERA\\MotifFiles\\Muhimu\\Muzik");
        emit queryAudioFilesInDirSig();
    }
private:

    JFileIO(QObject *parent = nullptr){
        Q_UNUSED(parent)

        worker->moveToThread(&fileIoThread);

        connect(&fileIoThread,&QThread::finished,worker,&QObject::deleteLater);
        connect(worker,&FilWorker::queryAllDirCompleted,this,&JFileIO::onFileQueryCompleted);
        connect(this,&JFileIO::queryAudioFilesInDirSig,worker,&FilWorker::queryAllDirectories);

        connect(this,&JFileIO::fetchFolders,worker,&FilWorker::loadFolders);
        connect(worker,&FilWorker::foldersFetched,this,&JFileIO::onFoldersFetched);

        connect(this,&JFileIO::addFolderSig,worker,&FilWorker::addFolderToLibs);
        connect(this,&JFileIO::deleteFolderSig,worker,&FilWorker::removeFolder);

        fileIoThread.start();



    }

private:

    FilWorker *worker=new FilWorker;

public slots:
    void  onFileQueryCompleted();
    void onFoldersFetched(QStringList folders);


public:
    void addFolder(QString path);
    void deleteFolder(QString dirPath);
    void getFolders();


    //worker signals
signals:

    void  queryAudioFilesInDirSig();

    void addFolderSig(QString path);
    void deleteFolderSig(QString path);
    void fetchFolders();


    //interface signals
signals:
 void foldersFetched(QStringList folders);
 void queringCompleted();


};

#endif // JFILEIO_H
