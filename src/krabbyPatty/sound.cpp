#include "sound.h"


Sound::Sound(int soundSettings)
{
    this->soundSettings = soundSettings;
    mediaPlayer = new QSoundEffect();
    mediaPlayer->setSource(QUrl::fromLocalFile(":/song/backgroundSong.wav"));
    mediaPlayer->setVolume(50);

    if(soundSettings == 2){
        mediaPlayer->play();
    }

}

void Sound::stopMusic(){
    if(soundSettings == 2)
        mediaPlayer->stop();

}
Sound::~Sound(){
     delete mediaPlayer;
}
