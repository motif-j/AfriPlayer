#include <QApplication>
#include <FelgoApplication>
#include <QtQml>
#include <QQmlApplicationEngine>
#include <QDir>


#include "src/adapters/jplaylistdataentry.h"
#include "src/adapters/dm_tracksdataentry.h"
#include "src/adapters/tracksadpater.h"
#include "src/adapters/ptracksadapter.h"
#include "src/adapters/musicfoldermodel.h"
#include <src/adapters/mtracksadapter.h>

#include "src/controllers/maincontroller.h"
#include <src/adapters/queueadapter.h>

#include "src/audio/jaudio.h"
#include <QString>

#include <src/utils/thumbnailprovider.h>
#include <src/utils/playergimageprovider.h>
#include <src/utils/particleimageprovider.h>

//#include <VLCQtQml/QmlPlayer.h>
//#include <VLCQtCore/Common.h>


// uncomment this line to add the Live Client Module and use live reloading with your custom C++ code
//#include <FelgoLiveClient>

QString formatTrackTime(QTime time){


    QString timeFormat;

    if(time.hour()==0){
        timeFormat="mm:ss ";
    }else{
        timeFormat="hh:mm:ss";
    }

    return time.toString( timeFormat);
}

int main(int argc, char *argv[])
{


    QApplication app(argc, argv);

   // QCoreApplication::setOrganizationName("AfrikTek");
   // QCoreApplication::setOrganizationDomain("afriktek.com");
   // QCoreApplication::setApplicationName("QPlayer");

   // VlcCommon::setPluginPath(app.applicationDirPath()+"plugins");

    qputenv("QML_DISABLE_DISK_CACHE","1");

    FelgoApplication felgo;

    // Use platform-specific fonts instead of Felgo's default font
    felgo.setPreservePlatformFonts(true);

    QQmlApplicationEngine engine;

    engine.addImageProvider(QLatin1String("thumbnail"),new ThumbnailProvider);
    engine.addImageProvider(QLatin1String("playerthumbnail"),new PlayerGImageProvider);
    engine.addImageProvider(QLatin1String("particle"),new ParticleImageProvider);

    felgo.initialize(&engine);


    // Set an optional license key from project file
    // This does not work if using Felgo Live, only for Felgo Cloud Builds and local builds
    felgo.setLicenseKey(PRODUCT_LICENSE_KEY);

    qmlRegisterSingletonType(QUrl("qrc:///qml/libraries/Constants.qml"),"com.afriktek.qplayer",1,0,"Constants");
    qmlRegisterSingletonType(QUrl("qrc:///qml/libraries/JColors.qml"),"com.afriktek.qplayer",1,0,"JColors");
    qmlRegisterSingletonType(QUrl("qrc:///qml/data/JQTrack.qml"),"com.afriktek.qplayer",1,0,"JQTrack");
    //  qmlRegisterSingletonType(QUrl("qrc:///qml/libraries/JQMusicController.qml"),"com.afriktek.qplayer",1,0,"JMuzik");
    // qmlRegisterType<BaseDataEntryModel>("com.afriktek.qplayer",1,0,"BaseDataEntryModel");


    qmlRegisterType<MTracksAdapter>("com.afriktek.qplayer",1,0,"TracksAdapter");

    qmlRegisterType<JPlaylistDataEntry>("com.afriktek.qplayer",1,0,"JPlaylistModel");
    qmlRegisterType<MusicFolderModel>("com.afriktek.qplayer",1,0,"FolderDataEntry");
    qmlRegisterType<JAudio>("com.afriktek.qplayer",1,0,"JAudio");
     qmlRegisterType<MainController>("com.afriktek.qplayer",1,0,"MainController");
     qmlRegisterType<QueueAdapter>("com.afriktek.qplayer",1,0,"QueueAdapter");
     qmlRegisterType<PTracksAdapter>("com.afriktek.qplayer",1,0,"PlaylistTracksAdapter");



  //  qmlRegisterType<VlcQmlPlayer>("com.afriktek.qplayer",1,0,"JAudioPlayer");
    // qmlRegisterType<QmlPlayer>("com.afriktek.qplayer",1,0,"JAudio");

    qRegisterMetaType<JTrack>("JTrack");
    qRegisterMetaType<JPlaylist>("JPlaylist");
    qRegisterMetaType<QDir>("QDir");

    // use this during development
    // for PUBLISHING, use the entry point below
    felgo.setMainQmlFileName(QStringLiteral("qml/Main.qml"));

    // use this instead of the above call to avoid deployment of the qml files and compile them into the binary with qt's resource system qrc
    // this is the preferred deployment option for publishing games to the app stores, because then your qml files and js files are protected
    // to avoid deployment of your qml files and images, also comment the DEPLOYMENTFOLDERS command in the .pro file
    // also see the .pro file for more details
    //felgo.setMainQmlFileName(QStringLiteral("qrc:/qml/Main.qml"));

    engine.load(QUrl(felgo.mainQmlFileName()));

    // to start your project as Live Client, comment (remove) the lines "felgo.setMainQmlFileName ..." & "engine.load ...",
    // and uncomment the line below
    //FelgoLiveClient client (&engine);





    return app.exec();
}
