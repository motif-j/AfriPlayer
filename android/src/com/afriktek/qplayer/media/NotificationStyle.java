package com.afriktek.qplayer.media;


import android.app.Notification;
import android.content.Context;
import android.media.MediaMetadata;
import android.support.v4.media.MediaDescriptionCompat;
import android.support.v4.media.MediaMetadataCompat;
import android.support.v4.media.session.MediaControllerCompat;
import android.support.v4.media.session.MediaSessionCompat;
import android.support.v4.media.session.PlaybackStateCompat;

import androidx.core.app.NotificationCompat;
import androidx.media.session.MediaButtonReceiver;

import com.afriktek.qplayer.R;

public class NotificationStyle {

    public static class Builder {
        private Context context;
        private MediaSessionCompat mediaSessionCompat;
        private NotificationCompat.Builder notificationBuilder;


        public Builder(Context context, MediaSessionCompat mediaSessionCompat) {
            this.context = context;
            this.mediaSessionCompat = mediaSessionCompat;

            MediaControllerCompat controller = mediaSessionCompat.getController();
            MediaMetadataCompat metadata = controller.getMetadata();
            MediaDescriptionCompat descriptionCompat = metadata.getDescription();

            Bitmap bmp=   BitmapFactory.decodeResource(context.getResources(),R.drawable.ic_launcher);
            notificationBuilder = new NotificationCompat.Builder(context, "AfrikPlayer");



            notificationBuilder.setContentTitle(descriptionCompat.getTitle());
            notificationBuilder.setContentText(descriptionCompat.getSubtitle());
            notificationBuilder.setLargeIcon(description.getIconBitmap());

            notificationBuilder.setVisibility(NotificationCompat.VISIBILITY_PUBLIC);
            notificationBuilder.setSmallIcon(R.drawable.muziq);

            notificationBuilder.addAction(
                    new NotificationCompat.Action(R.drawable.previous, "Previous",
                            MediaButtonReceiver.buildMediaButtonPendingIntent(context, PlaybackStateCompat.ACTION_SKIP_TO_PREVIOUS))
            );


        }


        public Builder pauseNotification() {
            notificationBuilder.addAction(new NotificationCompat.Action(
                    R.drawable.play,
                    "Play",
                    MediaButtonReceiver.buildMediaButtonPendingIntent(context, PlaybackStateCompat.ACTION_PLAY)
            )).addAction(
                    new NotificationCompat.Action(
                            R.drawable.next,
                            "Next",
                            MediaButtonReceiver.buildMediaButtonPendingIntent(context, PlaybackStateCompat.ACTION_SKIP_TO_NEXT)
                    ));

            return this;
        }

        public Notification build() {

            notificationBuilder.setStyle(
                    new androidx.media.app.NotificationCompat.MediaStyle()
                            .setMediaSession(mediaSessionCompat.getSessionToken())
                            .setShowActionsInCompactView(0, 1, 2)
            );

            return notificationBuilder.build();
        }
    }
}
