# allows to add DEPLOYMENTFOLDERS and links to the Felgo library and QtCreator auto-completion
CONFIG += felgo
CONFIG +=file_copies
CONFIG +=link_pkgconfig

QT +=core
QT +=gui
QT +=sql
QT +=multimedia
QT +=concurrent
QT +=quick




# uncomment this line to add the Live Client Module and use live reloading with your custom C++ code
# for the remaining steps to build a custom Live Code Reload app see here: https://felgo.com/custom-code-reload-app/
# CONFIG += felgo-live

# Project identifier and version
# More information: https://felgo.com/doc/felgo-publishing/#project-configuration
PRODUCT_IDENTIFIER = com.afriktek.qplayer
PRODUCT_VERSION_NAME = 1.0.0
PRODUCT_VERSION_CODE = 1

# Optionally set a license key that is used instead of the license key from
# main.qml file (App::licenseKey for your app or GameWindow::licenseKey for your game)
# Only used for local builds and Felgo Cloud Builds (https://felgo.com/cloud-builds)
# Not used if using Felgo Live
PRODUCT_LICENSE_KEY = ""


win32{

libtagfile.files=$$files("taglib/bin/*.dll")
COPIES += libtagfile
libtagfile.path=$$OUT_PWD

vlcfile.files=$$files("vlc/bin/*.dll")
COPIES += vlcfile
vlcfile.path=$$OUT_PWD


vlcplugins.source=vlc/bin/plugins
DEPLOYMENTFOLDERS += vlcplugins
}

#qmlFolder.source = qml
#DEPLOYMENTFOLDERS += qmlFolder # comment for publishing


assetsFolder.source = assets
DEPLOYMENTFOLDERS += assetsFolder

# Add more folders to ship with the application here

 RESOURCES += resources.qrc # uncomment for publishing

# NOTE: for PUBLISHING, perform the following steps:
# 1. comment the DEPLOYMENTFOLDERS += qmlFolder line above, to avoid shipping your qml files with the application (instead they get compiled to the app binary)
# 2. uncomment the resources.qrc file inclusion and add any qml subfolders to the .qrc file; this compiles your qml files and js files to the app binary and protects your source code
# 3. change the setMainQmlFile() call in main.cpp to the one starting with "qrc:/" - this loads the qml files from the resources
# for more details see the "Deployment Guides" in the Felgo Documentation

# during development, use the qmlFolder deployment because you then get shorter compilation times (the qml files do not need to be compiled to the binary but are just copied)
# also, for quickest deployment on Desktop disable the "Shadow Build" option in Projects/Builds - you can then select "Run Without Deployment" from the Build menu in Qt Creator if you only changed QML files; this speeds up application start, because your app is not copied & re-compiled but just re-interpreted


# The .cpp file which was generated for your project. Feel free to hack it.
SOURCES += main.cpp \
    src/adapters/mtracksadapter.cpp \
    src/adapters/musicfoldermodel.cpp \
    src/adapters/playlistadapter.cpp \
    src/adapters/ptracksadapter.cpp \
    src/adapters/queueadapter.cpp \
    src/adapters/searchadapter.cpp \
    src/adapters/tracksadpater.cpp \
    src/audio/jaudio.cpp \
    src/controllers/maincontroller.cpp \
    src/database/db_jmalkiadbinterface.cpp \
    src/engine/audioengine.cpp \
    src/engine/audioenginedroid.cpp \
    src/controllers/jplaylistcontroller.cpp \
    src/fileio/jfileworker.cpp \
    src/graphics/colorgenerator.cpp \
    src/utils/jsettings.cpp \
    src/utils/metadatamanager.cpp \
    src/utils/particleimageprovider.cpp \
    src/utils/playergimageprovider.cpp \
    src/utils/thumbnailprovider.cpp \
    src/utils/trackthumbnailprovider.cpp \
    src/workers/mainworker.cpp


android {
QT +=androidextras
    ANDROID_PACKAGE_SOURCE_DIR = $$PWD/android
    OTHER_FILES += android/AndroidManifest.xml       android/build.gradle

}

ios {
    QMAKE_INFO_PLIST = ios/Project-Info.plist
    OTHER_FILES += $$QMAKE_INFO_PLIST
}

# set application icons for win and macx
win32 {
    RC_FILE += win/app_icon.rc
}
macx {
    ICON = macx/app_icon.icns
}

DISTFILES += \
    android/src/com/afriktek/qplayer/JNIConnector.java \
    android/src/com/afriktek/qplayer/MusicList.java \
    android/src/com/afriktek/qplayer/QPlayerService.java \
    android/src/com/afriktek/qplayer/TestClass.java \
    android/src/com/afriktek/qplayer/media/MediaService.java \
    android/src/com/afriktek/qplayer/media/NotificationStyle.java \
    android/src/com/afriktek/qplayer/models/MusicTrack.java \
    qml/Main.qml \
    qml/audio/SoundManager.qml \
    qml/components/ActuallyPlayingOverlay.qml \
    qml/components/JIconButton.qml \
    qml/components/PlayerBar2.qml \
    qml/components/PlayerBarController.qml \
    qml/components/SearchPageRow.qml \
    qml/components/TracksEmptyLIstView.qml \
    qml/config.json \
    qml/data/JQTrack.qml \
    qml/libraries/Constants.qml \
    qml/libraries/JColors.qml \
    qml/libraries/JIconType.qml \
    qml/libraries/JQMusicController.qml \
    qml/logics/AppLogics.qml \
    qml/logics/JMusicLogic.qml \
    qml/models/AppModel.qml \
    qml/models/JMusicModel.qml \
    qml/models/MainPageDataModel.qml \
    qml/models/PlayingQueModel.qml \
    qml/models/PlaylistPageDataModel.qml \
    qml/models/RightMusicInfoModel.qml \
    qml/models/SearchPageModel.qml \
  #  qml/models/SettingsModel.qml \
    qml/models/SettingsModel.qml \
    qml/pages/FavoriteTracksPage.qml \
    qml/pages/MainPage.qml \
    qml/pages/PlaylistFolderPage.qml \
    qml/pages/PlaylistPage.qml \
    qml/pages/SearchPage.qml \
    qml/pages/SettingsPage.qml \
    qml/pages/TracksPage.qml \
    qml/settings/LibraryView.qml \
    qml/settings/PlaybackView.qml \
    qml/settings/PreferenceItem.qml \
    qml/settings/UserInterface.qml \
    qml/settings/models/FolderViewModel.qml \
    qml/settings/setviews/FolderView.qml \
    qml/settings/setviews/SwitchPreference.qml \
    qml/settings/setviews/UiView.qml \
    qml/ui/HomeHeader.qml \
    qml/ui/HomePlaylistView.qml \
    qml/ui/HomeTracksView.qml \
    qml/ui/ItemPlaylist2.qml \
    qml/ui/ItemSqTrack.qml \
    qml/ui/JIconButton.qml \
    qml/ui/MainTracksUi.qml \
    qml/ui/PlayingOverlay.qml \
    qml/ui/PlayingQueue.qml \
    qml/ui/PlaylistMenuItem.qml \
    qml/ui/QueTrack.qml \
    qml/utilities/ColorHelper.qml \
    qml/views/MainLeftView.qml \
    qml/views/MainRightView.qml \
    qml/views/MainView.qml \
    qml/views/MainCenterView.qml \
    qml/models/TracksPageDataModel.qml \
    qml/logics/TracksLogic.qml \
    qml/views/PlayerView.qml

HEADERS += \
    src/adapters/mtracksadapter.h \
    src/adapters/musicfoldermodel.h \
    src/adapters/playlistadapter.h \
    src/adapters/ptracksadapter.h \
    src/adapters/queueadapter.h \
    src/adapters/searchadapter.h \
    src/adapters/tracksadpater.h \
    src/audio/jaudio.h \
    src/controllers/maincontroller.h \
   src/database/db_jmalkiadbinterface.h \
    src/engine/audioengine.h \
    src/enums/jenums.h \
    src/fileio/jfileworker.h \
    src/graphics/colorgenerator.h \
    src/models/jmodels.h \
    src/controllers/jplaylistcontroller.h \
    src/models/jrole.h \
    src/utils/jsettings.h \
    src/utils/metadatamanager.h \
    src/utils/particleimageprovider.h \
    src/utils/playergimageprovider.h \
    src/utils/thumbnailprovider.h \
    src/utils/trackthumbnailprovider.h \
    src/workers/mainworker.h


INCLUDEPATH += $$PWD/.
DEPENDPATH += $$PWD/.



##VLC
unix|win32: LIBS += -L'C:/Program Files (x86)/VLC-Qt/lib/' -llibVLCQtCore.dll

INCLUDEPATH += 'C:/Program Files (x86)/VLC-Qt/include'
DEPENDPATH += 'C:/Program Files (x86)/VLC-Qt/include'

#TAG LIB
unix|win32: LIBS += -L'C:/Program Files (x86)/taglib/lib/' -llibtag.dll

INCLUDEPATH += 'C:/Program Files (x86)/taglib/include'
DEPENDPATH += 'C:/Program Files (x86)/taglib/include'





