package com.afriktek.qplayer;

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


import androidx.annotation.NonNull;
import androidx.annotation.Nullable;
import androidx.media.MediaBrowserServiceCompat;
import androidx.media.session.MediaButtonReceiver;
import org.qtproject.qt5.android.bindings.QtService;
import android.content.Context;
import java.util.List;

public class QPlayerService extends QtService implements AudioManager.OnAudioFocusChangeListener {

    private final String TAG="MediaPlayer";
    private MediaSessionCompat mediaSession;
    private PlaybackStateCompat.Builder playbackStateBuilder;


     public static void startService(Context ctx){

        System.out.println("JNI INVOKED IN SERVICE");
         ctx.startService(new Intent(ctx,QPlayerService.class));

        }


    @Override
    public void onCreate() {
        super.onCreate();

        System.out.println("Starting the Service");
        Log.d(TAG, "onCreate: INITIALIZING PLAYER ");
        initializeMediaSession();



    }

    @Override
    public void onDestroy() {
        super.onDestroy();
    }

    @Override
    public int onStartCommand(Intent intent, int flags, int startId) {
          int ret=super.onStartCommand(intent,flags,startId);
        initializeMediaButtonIntent();
        MediaButtonReceiver.handleIntent(mediaSession,intent);

        return ret;
    }

    @Nullable
    @Override
    public IBinder onBind(Intent intent) {
        return null;
    }



    private void initializeMediaSession(){

        playbackStateBuilder =new PlaybackStateCompat.Builder();
        playbackStateBuilder.setActions(PlaybackStateCompat.ACTION_PLAY|PlaybackStateCompat.ACTION_PAUSE);

        setPlaybackState(PlaybackStateCompat.STATE_STOPPED);
        mediaSession=new MediaSessionCompat(this,"Session");
        mediaSession.setFlags(MediaSessionCompat.FLAG_HANDLES_MEDIA_BUTTONS|MediaSessionCompat.FLAG_HANDLES_TRANSPORT_CONTROLS);
        ///setSessionToken(getSessionToken());
        mediaSession.setPlaybackState(playbackStateBuilder.build());

        mediaSession.setCallback(new MediaSessionCallback());

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
