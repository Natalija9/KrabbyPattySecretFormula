#ifndef SOUND_H
#define SOUND_H


#include <QtMultimedia/QSoundEffect>


class Sound
{
public:
    Sound(int soundSettings);
    ~Sound();

    QSoundEffect *mediaPlayer;
    void stopMusic();
private:
    int soundSettings;
};


#endif // SOUND_H
