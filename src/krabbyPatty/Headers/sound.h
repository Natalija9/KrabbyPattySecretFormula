#ifndef SOUND_H
#define SOUND_H


#include <QtMultimedia/QSoundEffect>


class Sound
{
public:
    Sound(bool isSoundOn);
    QSoundEffect *mediaPlayer;
    void stopMusic();
    ~Sound();

private:
    bool soundOn;
};


#endif // SOUND_H
