#include "settings.h"

Settings::Settings()
{
    _sound = 2;
    _mode = 0;
}

void Settings::setSound(int value) {
    _sound = value;
}

void Settings::setMode(int value) {
    _mode = value;
}

int Settings::getSound() {
    return _sound;
}

int Settings::getMode() {
    return _mode;
}
