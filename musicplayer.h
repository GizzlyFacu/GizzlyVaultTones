#ifndef MUSICPLAYER_H
#define MUSICPLAYER_H

#include <QObject>
#include <QMediaPlayer>
#include <QAudioOutput>
class MusicPlayer : public QObject
{
    Q_OBJECT
    Q_PROPERTY(bool playPause READ playPause WRITE setPlayPause NOTIFY playPauseChanged FINAL)
    Q_PROPERTY(int sliderPosition READ sliderPosition WRITE setSliderPosition NOTIFY sliderPositionChanged FINAL)
    Q_PROPERTY(int sliderDuration READ sliderDuration NOTIFY sliderDurationChanged FINAL)
public:
    explicit MusicPlayer(QObject *parent = nullptr);

    bool playPause() const;
    void setPlayPause(bool newPlayPause);

    int sliderPosition() const;
    void setSliderPosition(int newSliderPosition);

    int sliderDuration() const;



signals:
    void playPauseChanged();
    void sliderPositionChanged();
    void sliderDurationChanged();

public slots:
    void playMusic();
    void pausedSlider(int Position);
    void configSong(QUrl SongUrl);
    //volume- controller
    void volumeController(float value);
private slots:
    //slider- position
    void connectSlider();
    void refreshSliderLoop();
    void disconnectSlider();
    //slider- duration
    void connectMusicDuration();
    void refreshMusicDuration();

private:
    QMediaPlayer m_mediaPlayer;
    bool m_playPause=true;
    bool playButtonPressed=false;
    int m_sliderPosition=0;
    int m_sliderDuration=0;


};

#endif // MUSICPLAYER_H
