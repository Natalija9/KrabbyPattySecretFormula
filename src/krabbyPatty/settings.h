#ifndef SETTINGS_H
#define SETTINGS_H


class Settings
{
public:
    Settings();

    void setSound(int value);
    void setMode(int value);

private:
    int _sound;
    int _mode;
};

#endif // SETTINGS_H
