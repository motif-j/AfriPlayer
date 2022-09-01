#include "jfileworker.h"

JFileWorker::JFileWorker(QObject *parent)
    : QObject{parent}
{
    threadpool=new QThreadPool;
    threadpool->setMaxThreadCount(2);
    threadpool->setExpiryTimeout(-1);


}

QFuture<int> JFileWorker::queryAllFiles()
{

    return  QtConcurrent::run(threadpool,[this](){
        auto dirs=db.getFolders();

        if(!dirs.isEmpty()){

            foreach(QString dirPath,dirs){

                QDir *directory=new QDir(dirPath.remove(0,8));

                if(!directory->exists()){
                    qDebug()<<"Query dir not exist"<<dirs.count();


                    break;
                }

                qDebug()<<"Query "<<directory->path();
                QStringList filters;

                filters<<"*.m4a"<<"*.mp3"<<"*.wav"<<"*.aac"<<"*.flac"<<"*.ogg";//<<"*.mp4"<<"*.mkv";

                directory->setNameFilters(filters);

                directory->setSorting(QDir::Time);

                QFileInfoList dirList=directory->entryInfoList();

                QDirIterator dirIterator(*directory,QDirIterator::Subdirectories);


                while(dirIterator.hasNext()){
                    auto *dirEntryPath=new QString(dirIterator.next());


                    QFileInfo dirInfo(*dirEntryPath);



                    if(dirInfo.isFile()){
                        // QString path=dirInfo.path();

                        QString plName=dirInfo.absoluteDir().dirName();

                        JTrack track=MetaDataManager::retrieveMetaInfo(dirInfo);
                        db.addNewTrack(track);

                        //confirm that it is not root folder


                        //add this folder to folder playlist

                        JPlaylist pl;
                        pl.isFolder=true;
                        pl.playlistTitle=plName;

                        //check if the playlist exists
                        // int eq=QString::compare(lstPlaylist.playlistTitle,plName)


                        db.addNewPlaylist(pl);



                        //get the last playlist
                        //get the last record
                        JTrack lstTrack=db.getLastTrack();
                        JPlaylist lstPlaylist=db.getLastPlaylist();



                        db.addTrackToPlaylist(lstTrack,lstPlaylist.playlistId);
                        //add the track to folder playlist


                    }

                }
            }

        }



        settings.setIsQuering(false);

        return 1;

    });



}
