#include "Headers/settings.h"

Settings::Settings(){
    _sound = true;
    _mode = Mode::EasyMode;
}

void Settings::setSound(int isSoundOn){
    if(!isSoundOn)
        _sound = false;
    else
        _sound = true;
}

void Settings::setMode(Mode mode){
    _mode = mode;
}

bool Settings::getSound(){
    return _sound;
}

Mode Settings::getMode(){
    return _mode;
}

Settings::~Settings(){

}
