# Created by and for Qt Creator This file was created for editing the project sources only.
# You may attempt to use it for building too, by modifying this file here.

#TARGET = JPlayerMain

QT = core gui widgets

HEADERS = \
   $$PWD/taglib/include/taglib/aifffile.h \
   $$PWD/taglib/include/taglib/aiffproperties.h \
   $$PWD/taglib/include/taglib/apefile.h \
   $$PWD/taglib/include/taglib/apefooter.h \
   $$PWD/taglib/include/taglib/apeitem.h \
   $$PWD/taglib/include/taglib/apeproperties.h \
   $$PWD/taglib/include/taglib/apetag.h \
   $$PWD/taglib/include/taglib/asfattribute.h \
   $$PWD/taglib/include/taglib/asffile.h \
   $$PWD/taglib/include/taglib/asfpicture.h \
   $$PWD/taglib/include/taglib/asfproperties.h \
   $$PWD/taglib/include/taglib/asftag.h \
   $$PWD/taglib/include/taglib/attachedpictureframe.h \
   $$PWD/taglib/include/taglib/audioproperties.h \
   $$PWD/taglib/include/taglib/chapterframe.h \
   $$PWD/taglib/include/taglib/commentsframe.h \
   $$PWD/taglib/include/taglib/eventtimingcodesframe.h \
   $$PWD/taglib/include/taglib/fileref.h \
   $$PWD/taglib/include/taglib/flacfile.h \
   $$PWD/taglib/include/taglib/flacmetadatablock.h \
   $$PWD/taglib/include/taglib/flacpicture.h \
   $$PWD/taglib/include/taglib/flacproperties.h \
   $$PWD/taglib/include/taglib/generalencapsulatedobjectframe.h \
   $$PWD/taglib/include/taglib/id3v1genres.h \
   $$PWD/taglib/include/taglib/id3v1tag.h \
   $$PWD/taglib/include/taglib/id3v2.h \
   $$PWD/taglib/include/taglib/id3v2extendedheader.h \
   $$PWD/taglib/include/taglib/id3v2footer.h \
   $$PWD/taglib/include/taglib/id3v2frame.h \
   $$PWD/taglib/include/taglib/id3v2framefactory.h \
   $$PWD/taglib/include/taglib/id3v2header.h \
   $$PWD/taglib/include/taglib/id3v2synchdata.h \
   $$PWD/taglib/include/taglib/id3v2tag.h \
   $$PWD/taglib/include/taglib/infotag.h \
   $$PWD/taglib/include/taglib/itfile.h \
   $$PWD/taglib/include/taglib/itproperties.h \
   $$PWD/taglib/include/taglib/modfile.h \
   $$PWD/taglib/include/taglib/modfilebase.h \
   $$PWD/taglib/include/taglib/modproperties.h \
   $$PWD/taglib/include/taglib/modtag.h \
   $$PWD/taglib/include/taglib/mp4atom.h \
   $$PWD/taglib/include/taglib/mp4coverart.h \
   $$PWD/taglib/include/taglib/mp4file.h \
   $$PWD/taglib/include/taglib/mp4item.h \
   $$PWD/taglib/include/taglib/mp4properties.h \
   $$PWD/taglib/include/taglib/mp4tag.h \
   $$PWD/taglib/include/taglib/mpcfile.h \
   $$PWD/taglib/include/taglib/mpcproperties.h \
   $$PWD/taglib/include/taglib/mpegfile.h \
   $$PWD/taglib/include/taglib/mpegheader.h \
   $$PWD/taglib/include/taglib/mpegproperties.h \
   $$PWD/taglib/include/taglib/oggfile.h \
   $$PWD/taglib/include/taglib/oggflacfile.h \
   $$PWD/taglib/include/taglib/oggpage.h \
   $$PWD/taglib/include/taglib/oggpageheader.h \
   $$PWD/taglib/include/taglib/opusfile.h \
   $$PWD/taglib/include/taglib/opusproperties.h \
   $$PWD/taglib/include/taglib/ownershipframe.h \
   $$PWD/taglib/include/taglib/podcastframe.h \
   $$PWD/taglib/include/taglib/popularimeterframe.h \
   $$PWD/taglib/include/taglib/privateframe.h \
   $$PWD/taglib/include/taglib/relativevolumeframe.h \
   $$PWD/taglib/include/taglib/rifffile.h \
   $$PWD/taglib/include/taglib/s3mfile.h \
   $$PWD/taglib/include/taglib/s3mproperties.h \
   $$PWD/taglib/include/taglib/speexfile.h \
   $$PWD/taglib/include/taglib/speexproperties.h \
   $$PWD/taglib/include/taglib/synchronizedlyricsframe.h \
   $$PWD/taglib/include/taglib/tableofcontentsframe.h \
   $$PWD/taglib/include/taglib/tag.h \
   $$PWD/taglib/include/taglib/tag_c.h \
   $$PWD/taglib/include/taglib/taglib.h \
   $$PWD/taglib/include/taglib/taglib_config.h \
   $$PWD/taglib/include/taglib/taglib_export.h \
   $$PWD/taglib/include/taglib/tbytevector.h \
   $$PWD/taglib/include/taglib/tbytevectorlist.h \
   $$PWD/taglib/include/taglib/tbytevectorstream.h \
   $$PWD/taglib/include/taglib/tdebuglistener.h \
   $$PWD/taglib/include/taglib/textidentificationframe.h \
   $$PWD/taglib/include/taglib/tfile.h \
   $$PWD/taglib/include/taglib/tfilestream.h \
   $$PWD/taglib/include/taglib/tiostream.h \
   $$PWD/taglib/include/taglib/tlist.h \
   $$PWD/taglib/include/taglib/tlist.tcc \
   $$PWD/taglib/include/taglib/tmap.h \
   $$PWD/taglib/include/taglib/tmap.tcc \
   $$PWD/taglib/include/taglib/tpropertymap.h \
   $$PWD/taglib/include/taglib/trefcounter.h \
   $$PWD/taglib/include/taglib/trueaudiofile.h \
   $$PWD/taglib/include/taglib/trueaudioproperties.h \
   $$PWD/taglib/include/taglib/tstring.h \
   $$PWD/taglib/include/taglib/tstringlist.h \
   $$PWD/taglib/include/taglib/uniquefileidentifierframe.h \
   $$PWD/taglib/include/taglib/unknownframe.h \
   $$PWD/taglib/include/taglib/unsynchronizedlyricsframe.h \
   $$PWD/taglib/include/taglib/urllinkframe.h \
   $$PWD/taglib/include/taglib/vorbisfile.h \
   $$PWD/taglib/include/taglib/vorbisproperties.h \
   $$PWD/taglib/include/taglib/wavfile.h \
   $$PWD/taglib/include/taglib/wavpackfile.h \
   $$PWD/taglib/include/taglib/wavpackproperties.h \
   $$PWD/taglib/include/taglib/wavproperties.h \
   $$PWD/taglib/include/taglib/xingheader.h \
   $$PWD/taglib/include/taglib/xiphcomment.h \
   $$PWD/taglib/include/taglib/xmfile.h \
   $$PWD/taglib/include/taglib/xmproperties.h \
   $$PWD/db_jmalkiadbinterface.h \
   $$PWD/dm_tracksdataentry.h \
   $$PWD/jmetaretriever.h \
   $$PWD/jmodels.h \
   $$PWD/jmusiccontroller.h \
   $$PWD/jmusiccontrollerinterface.h \
   $$PWD/jmusiccontrollerworker.h \
   $$PWD/jplaylistcontroller.h \
   $$PWD/jplaylistdataentry.h \
   $$PWD/jrole.h \
   $$PWD/qmd_qtrack.h

SOURCES = \
   $$PWD/android/res/drawable-hdpi/ic_launcher.png \
   $$PWD/android/res/drawable-mdpi/ic_launcher.png \
   $$PWD/android/res/drawable-xhdpi/ic_launcher.png \
   $$PWD/android/res/drawable-xxhdpi/ic_launcher.png \
   $$PWD/android/res/values/strings.xml \
   $$PWD/android/res/xml/file_paths.xml \
   $$PWD/android/src/com/afriktek/qplayer/TestClass.java \
   $$PWD/android/AndroidManifest.xml \
   $$PWD/android/build.gradle \
   $$PWD/assets/cover.png \
   $$PWD/assets/felgo-logo.png \
   $$PWD/assets/font_icon.otf \
   $$PWD/assets/lcd.ttf \
   $$PWD/assets/malkia.db \
   $$PWD/assets/more_horizontal.png \
   $$PWD/assets/pause.png \
   $$PWD/assets/play.png \
   $$PWD/assets/playlist.png \
   $$PWD/assets/qt.png \
   $$PWD/ios/Assets.xcassets/AppIcon.appiconset/Contents.json \
   $$PWD/ios/Assets.xcassets/AppIcon.appiconset/Icon-App-20x20@1x.png \
   $$PWD/ios/Assets.xcassets/AppIcon.appiconset/Icon-App-20x20@2x-1.png \
   $$PWD/ios/Assets.xcassets/AppIcon.appiconset/Icon-App-20x20@2x.png \
   $$PWD/ios/Assets.xcassets/AppIcon.appiconset/Icon-App-20x20@3x.png \
   $$PWD/ios/Assets.xcassets/AppIcon.appiconset/Icon-App-29x29@1x.png \
   $$PWD/ios/Assets.xcassets/AppIcon.appiconset/Icon-App-29x29@2x-1.png \
   $$PWD/ios/Assets.xcassets/AppIcon.appiconset/Icon-App-29x29@2x.png \
   $$PWD/ios/Assets.xcassets/AppIcon.appiconset/Icon-App-29x29@3x.png \
   $$PWD/ios/Assets.xcassets/AppIcon.appiconset/Icon-App-40x40@1x.png \
   $$PWD/ios/Assets.xcassets/AppIcon.appiconset/Icon-App-40x40@2x-1.png \
   $$PWD/ios/Assets.xcassets/AppIcon.appiconset/Icon-App-40x40@2x.png \
   $$PWD/ios/Assets.xcassets/AppIcon.appiconset/Icon-App-40x40@3x.png \
   $$PWD/ios/Assets.xcassets/AppIcon.appiconset/Icon-App-60x60@2x.png \
   $$PWD/ios/Assets.xcassets/AppIcon.appiconset/Icon-App-60x60@3x.png \
   $$PWD/ios/Assets.xcassets/AppIcon.appiconset/Icon-App-76x76@1x.png \
   $$PWD/ios/Assets.xcassets/AppIcon.appiconset/Icon-App-76x76@2x.png \
   $$PWD/ios/Assets.xcassets/AppIcon.appiconset/Icon-App-83.5x83.5@2x.png \
   $$PWD/ios/Assets.xcassets/AppIcon.appiconset/ItunesArtwork@2x.png \
   $$PWD/ios/Assets.xcassets/Contents.json \
   $$PWD/ios/Launch Screen.storyboard \
   $$PWD/ios/Project-Info.plist \
   $$PWD/macx/app_icon.icns \
   $$PWD/qml/audio/SoundManager.qml \
   $$PWD/qml/components/ActuallyPlayingOverlay.qml \
   $$PWD/qml/components/PlayerBar2.qml \
   $$PWD/qml/components/PlayerBarController.qml \
   $$PWD/qml/components/TracksEmptyLIstView.qml \
   $$PWD/qml/data/JQTrack.qml \
   $$PWD/qml/libraries/Constants.qml \
   $$PWD/qml/libraries/JColors.qml \
   $$PWD/qml/libraries/JIconType.qml \
   $$PWD/qml/libraries/JQMusicController.qml \
   $$PWD/qml/logics/AppLogics.qml \
   $$PWD/qml/logics/JMusicLogic.qml \
   $$PWD/qml/logics/TracksLogic.qml \
   $$PWD/qml/models/AppModel.qml \
   $$PWD/qml/models/JMusicModel.qml \
   $$PWD/qml/models/MainPageDataModel.qml \
   $$PWD/qml/models/PlayingQueModel.qml \
   $$PWD/qml/models/PlaylistPageDataModel.qml \
   $$PWD/qml/models/RightMusicInfoModel.qml \
   $$PWD/qml/models/TracksPageDataModel.qml \
   $$PWD/qml/pages/FavoriteTracksPage.qml \
   $$PWD/qml/pages/MainPage.qml \
   $$PWD/qml/pages/PlaylistPage.qml \
   $$PWD/qml/pages/SearchPage.qml \
   $$PWD/qml/pages/TracksPage.qml \
   $$PWD/qml/ui/HomeHeader.qml \
   $$PWD/qml/ui/HomePlaylistView.qml \
   $$PWD/qml/ui/HomeTracksView.qml \
   $$PWD/qml/ui/ItemPlaylist2.qml \
   $$PWD/qml/ui/ItemSqTrack.qml \
   $$PWD/qml/ui/JIconButton.qml \
   $$PWD/qml/ui/MainTracksUi.qml \
   $$PWD/qml/ui/PlayingOverlay.qml \
   $$PWD/qml/ui/PlayingQueue.qml \
   $$PWD/qml/ui/QueTrack.qml \
   $$PWD/qml/utilities/ColorHelper.qml \
   $$PWD/qml/views/MainCenterView.qml \
   $$PWD/qml/views/MainLeftView.qml \
   $$PWD/qml/views/MainRightView.qml \
   $$PWD/qml/views/MainView.qml \
   $$PWD/qml/views/PlayerView.qml \
   $$PWD/qml/config.json \
   $$PWD/qml/Main.qml \
   $$PWD/taglib/bin/libtag.dll \
   $$PWD/taglib/bin/libtag_c.dll \
   $$PWD/taglib/bin/taglib-config.cmd \
   $$PWD/taglib/lib/pkgconfig/taglib.pc \
   $$PWD/taglib/lib/pkgconfig/taglib_c.pc \
   $$PWD/taglib/lib/libtag.dll.a \
   $$PWD/taglib/lib/libtag_c.dll.a \
   $$PWD/win/app_icon.ico \
   $$PWD/win/app_icon.rc \
   $$PWD/db_jmalkiadbinterface.cpp \
   $$PWD/dm_tracksdataentry.cpp \
   $$PWD/jmusiccontroller.cpp \
   $$PWD/jplaylistcontroller.cpp \
   $$PWD/jplaylistdataentry.cpp \
   $$PWD/main.cpp \
   $$PWD/qmd_qtrack.cpp \
   $$PWD/QPlayer.pro \
   $$PWD/resources.qrc

INCLUDEPATH = \
    $$PWD/. \
    $$PWD/taglib/include/taglib

#DEFINES = 

