package com.afriktek.qplayer.models;

public class MusicTrack {

    private String trackName;
    private String artistName;
    private String trackUrl;

    public MusicTrack(String trackName, String artistName, String trackUrl) {
        this.trackName = trackName;
        this.artistName = artistName;
        this.trackUrl = trackUrl;
    }

    public String getTrackName() {
        return trackName;
    }

    public void setTrackName(String trackName) {
        this.trackName = trackName;
    }

    public String getArtistName() {
        return artistName;
    }

    public void setArtistName(String artistName) {
        this.artistName = artistName;
    }

    public String getTrackUrl() {
        return trackUrl;
    }

    public void setTrackUrl(String trackUrl) {
        this.trackUrl = trackUrl;
    }
}
