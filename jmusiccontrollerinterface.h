#ifndef JMUSICCONTROLLERINTERFACE_H
#define JMUSICCONTROLLERINTERFACE_H

#include <QObject>
#include <QtQml/qqml.h>
#include "jmusiccontroller.h"

/*
*Having this class feels like redudancy
*However I want the music controller to be a single instance in the entire project.
*To achieve that I have opted for an interface class which will be called from
*the QML and instantiate only a single instance of the music controller.
*The Music controller will be in charge of controlling staffs like current playing track, playlist
*This interface is mainly applicable for the whole QML app
*/

class JMusicControllerInterface : public QObject
{
    Q_OBJECT
    QML_ELEMENT
    QML_SINGLETON


public:
    JMusicControllerInterface(QObject *parent = nullptr){

        Q_UNUSED(parent)
        qDebug()<<"INITIALIZING INTERFACE";

        //connect directly to the signals of the main controller
        connect(&musicController,&JMusicController::trackFetched,this,&JMusicControllerInterface::trackFetchedFromRepo);

    }

     ~JMusicControllerInterface() {

        qDebug()<<"DESTROYING INTERFACE";
    }
    //music controller slots
public slots:
   void  handleFetchedTrack(QVariantMap trackMap){

       emit trackFetchedFromRepo(trackMap);
    }

   //qml interface slots
public slots:

    void getTrack(int trackId){
        musicController.getTrack(trackId);

    }

//These signals directly communicate with the QML file
signals:
    void trackFetchedFromRepo(QVariantMap trackMap);

private:
    JMusicController &musicController=JMusicController::getInstance();

};
#endif // JMUSICCONTROLLERINTERFACE_H
