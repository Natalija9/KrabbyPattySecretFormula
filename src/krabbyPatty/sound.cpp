#include "sound.h"


Sound::Sound()
{
    mediaPlayer = new QSoundEffect();
    mediaPlayer->setSource(QUrl::fromLocalFile(":/song/backgroundSong.wav"));
    mediaPlayer->setVolume(50);

}

void Sound::playMusic(){
    mediaPlayer->play();
}

Sound::~Sound(){
    mediaPlayer->stop();
    delete mediaPlayer;
}
