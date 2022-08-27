
package com.afriktek.qplayer;

import com.afriktek.qplayer.media.*;
import android.content.Context;
import android.content.Intent;
import androidx.core.content.ContextCompat;


public class JNIConnector {

    public static void startService(Context context){

        System.out.println("JNI INVOKED");
        ContextCompat.startForegroundService(context,new Intent(context,MediaService.class));

        }

}
