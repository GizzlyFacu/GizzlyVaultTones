#include "musicplayer.h"
#include <QAudioDevice>

#include <QMediaDevices>
#include <QDebug>
MusicPlayer::MusicPlayer(QObject *parent)
    : QObject{parent}
{
 connectMusicDuration();
}

void MusicPlayer::configSong(QUrl SongUrl)
{
    setPlayPause(true);
    m_mediaPlayer.setSource(SongUrl);
    m_mediaPlayer.setAudioOutput(new QAudioOutput(&m_mediaPlayer));//puede ser

}

void MusicPlayer::playMusic()
{
    if(m_playPause){
        m_mediaPlayer.play();
        playButtonPressed=true;
        connectSlider();
    }else {
        disconnectSlider();
        m_mediaPlayer.pause();
        playButtonPressed=false;
    }
    setPlayPause(!m_playPause);

}

void MusicPlayer::pausedSlider(int Position)
{
    if(playButtonPressed){
        if(m_playPause){
            m_mediaPlayer.setPosition(Position*1000);
            refreshSliderLoop();
            connectSlider();
            m_mediaPlayer.play();
        }else {
            disconnectSlider();
            m_mediaPlayer.pause();
        }
        setPlayPause(!m_playPause);
    }
    m_mediaPlayer.setPosition(Position*1000);
    refreshSliderLoop();
}


//---------Slider Controller---------------------

void MusicPlayer::connectSlider()
{
    connect(&m_mediaPlayer,&QMediaPlayer::positionChanged,this,&MusicPlayer::refreshSliderLoop);
}

void MusicPlayer::refreshSliderLoop()
{
    if(m_mediaPlayer.duration()==m_mediaPlayer.position()){
        m_mediaPlayer.stop();
        setPlayPause(!m_playPause);
    }
    m_sliderPosition=m_mediaPlayer.position()/1000;
    emit sliderPositionChanged();
}

void MusicPlayer::disconnectSlider()
{
    disconnect(&m_mediaPlayer,&QMediaPlayer::positionChanged,this,&MusicPlayer::refreshSliderLoop);
}
//----------------MusicDuration------------------

void MusicPlayer::connectMusicDuration()
{
    connect(&m_mediaPlayer,&QMediaPlayer::durationChanged,this,&MusicPlayer::refreshMusicDuration);
}

void MusicPlayer::refreshMusicDuration()
{
    m_sliderDuration=m_mediaPlayer.duration()/1000;
    //qDebug()<<"New Music Duration: "<< m_sliderDuration;
    emit sliderDurationChanged();
}
//----------Auto QPROPERTIES----------------------
bool MusicPlayer::playPause() const
{
    return m_playPause;
}

void MusicPlayer::setPlayPause(bool newPlayPause)
{
    if (m_playPause == newPlayPause)
        return;
    m_playPause = newPlayPause;
    emit playPauseChanged();
}

int MusicPlayer::sliderPosition() const
{
    return m_sliderPosition;
}

void MusicPlayer::setSliderPosition(int newSliderPosition)
{
    if (m_sliderPosition == newSliderPosition)
        return;
    m_sliderPosition = newSliderPosition;
    emit sliderPositionChanged();
}

int MusicPlayer::sliderDuration() const
{
    return m_sliderDuration;
}
