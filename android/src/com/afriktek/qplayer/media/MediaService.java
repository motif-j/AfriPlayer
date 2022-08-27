package com.afriktek.qplayer.media;


import android.graphics.BitmapFactory;
import android.graphics.Bitmap;

import android.os.Build;
import android.app.NotificationManager;
import android.app.NotificationChannel;
import android.app.Notification;
import androidx.core.app.NotificationManagerCompat;


import android.app.PendingIntent;
import android.app.Service;
import android.content.Intent;
import android.media.AudioManager;
import android.net.Uri;
import android.os.Bundle;
import android.os.IBinder;
import android.support.v4.media.MediaBrowserCompat;
import android.support.v4.media.session.MediaSessionCompat;
import android.support.v4.media.session.PlaybackStateCompat;
import android.util.Log;


import android.widget.Toast;
import androidx.annotation.NonNull;
import androidx.annotation.Nullable;

import androidx.core.content.ContextCompat;
import androidx.media.MediaBrowserServiceCompat;
import androidx.media.session.MediaButtonReceiver;
import org.qtproject.qt5.android.bindings.QtService;

import java.util.List;

public class MediaService extends MediaBrowserServiceCompat implements AudioManager.OnAudioFocusChangeListener {

    private final String TAG="MediaPlayer";
    private MediaSessionCompat mediaSession;
    private PlaybackStateCompat.Builder playbackStateBuilder;



    @Nullable
      @Override
      public BrowserRoot onGetRoot(@NonNull String clientPackageName, int clientUid, @Nullable Bundle rootHints) {
          return new BrowserRoot("AfriMuzik",null);
      }

      @Override
      public void onLoadChildren(@NonNull String parentId, @NonNull Result<List<MediaBrowserCompat.MediaItem>> result) {

          result.sendResult(null);
      }



    @Override
    public void onCreate() {
        super.onCreate();

        createNotificationChannel();

         Toast.makeText(this,"INIT Service ",Toast.LENGTH_SHORT).show();
       initializeMediaSession();
         Toast.makeText(this,"Creating Service ",Toast.LENGTH_SHORT).show();
    }

    @Override
    public void onDestroy() {
        super.onDestroy();
        mediaSession.setActive(false);
    }

    @Override
    public int onStartCommand(Intent intent, int flags, int startId) {
      // int ret =super.onStartCommand(intent,flags,startId);


     //  startForeground(1,pauseNotification());
    //   NotificationManagerCompat.from(this).notify(1, pauseNotification());
    //   Toast.makeText(this,"Starting service ",Toast.LENGTH_SHORT).show();


        initializeMediaButtonIntent();
        MediaButtonReceiver.handleIntent(mediaSession,intent);


        return START_STICKY;
    }

    @Nullable
    @Override
    public IBinder onBind(Intent intent) {
        return null;
    }

private Notification pauseNotification(){

  return new NotificationStyle.Builder(this,mediaSession)
           .pauseNotification()
           .build();
}

private void createNotificationChannel() {
    // Create the NotificationChannel, but only on API 26+ because
    // the NotificationChannel class is new and not in the support library
    if (Build.VERSION.SDK_INT >= Build.VERSION_CODES.O) {
       String name = "AfriMuzik";
        String description = "Channel for managing audio player";
        int importance = NotificationManager.IMPORTANCE_LOW;
        NotificationChannel channel = new NotificationChannel("AfrikPlayer", name, importance);
        channel.setDescription(description);

        // Register the channel with the system; you can't change the importance
        // or other notification behaviors after this
        NotificationManager notificationManager=getSystemService(NotificationManager.class);

        notificationManager.createNotificationChannel(channel);
    }
}

    private void initializeMediaSession(){

        playbackStateBuilder =new PlaybackStateCompat.Builder();
        playbackStateBuilder.setActions(PlaybackStateCompat.ACTION_PLAY|PlaybackStateCompat.ACTION_PAUSE);


        mediaSession=new MediaSessionCompat(this,"Session");
        mediaSession.setFlags(MediaSessionCompat.FLAG_HANDLES_MEDIA_BUTTONS|MediaSessionCompat.FLAG_HANDLES_TRANSPORT_CONTROLS);

        System.out.println("TOKEN "+mediaSession.getSessionToken());

        setSessionToken(mediaSession.getSessionToken());
        mediaSession.setPlaybackState(playbackStateBuilder.build());

        mediaSession.setCallback(new MediaSessionCallback());

         mediaSession.setActive(true);
          setPlaybackState(PlaybackStateCompat.STATE_STOPPED);

    }

    private void initializeMediaButtonIntent(){
        Intent intent =new Intent(Intent.ACTION_MEDIA_BUTTON);
        intent.setClass(this, MediaButtonReceiver.class);

        PendingIntent pendingIntent=PendingIntent.getBroadcast(this,0,intent,PendingIntent.FLAG_IMMUTABLE);
        mediaSession.setMediaButtonReceiver(pendingIntent);
    }

    private void setPlaybackState(int playbackState){
        playbackStateBuilder.setState(playbackState,0,1f);

        mediaSession.setPlaybackState(playbackStateBuilder.build());
    }

    @Override
    public void onAudioFocusChange(int i) {

    }

    private class MediaSessionCallback extends MediaSessionCompat.Callback{
        @Override
        public void onPlay() {
            super.onPlay();
        }

        @Override
        public void onPause() {
            super.onPause();
        }

        @Override
        public void onPlayFromUri(Uri uri, Bundle extras) {
            super.onPlayFromUri(uri, extras);
        }

    }
}
