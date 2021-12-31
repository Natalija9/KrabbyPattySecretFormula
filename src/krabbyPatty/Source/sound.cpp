#include "Headers/sound.h"


Sound::Sound(bool isSoundOn){
    this->soundOn = isSoundOn;
    mediaPlayer = new QSoundEffect();
    mediaPlayer->setSource(QUrl::fromLocalFile(":/song/backgroundSong.wav"));
    mediaPlayer->setVolume(50);

    if(soundOn){
        mediaPlayer->play();
    }
}

void Sound::stopMusic(){
    if(soundOn)
        mediaPlayer->stop();

}
Sound::~Sound(){
     delete mediaPlayer;
}
