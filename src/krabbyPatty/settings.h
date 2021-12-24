#ifndef SETTINGS_H
#define SETTINGS_H


class Settings
{
public:
    Settings();

    void setSound(int value);
    void setMode(int value);
    int getSound();
    int getMode();

private:
    int _sound;
    int _mode;
};

#endif // SETTINGS_H
