#ifndef SOUND_H
#define SOUND_H


#include <QtMultimedia/QSoundEffect>



class Sound
{
public:
    Sound();

    ~Sound();
    QSoundEffect *mediaPlayer;
    void playMusic();
};


#endif // SOUND_H
