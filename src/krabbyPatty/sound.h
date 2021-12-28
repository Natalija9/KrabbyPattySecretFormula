#ifndef SOUND_H
#define SOUND_H


#include <QtMultimedia/QSoundEffect>


class Sound
{
public:
    Sound(bool isSoundOn);
    ~Sound();

    QSoundEffect *mediaPlayer;
    void stopMusic();
private:
    bool soundOn;
};


#endif // SOUND_H
