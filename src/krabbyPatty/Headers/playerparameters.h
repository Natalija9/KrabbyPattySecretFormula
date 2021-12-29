#ifndef PLAYERPARAMETERS_H
#define PLAYERPARAMETERS_H

#include <QApplication>
#include <QScreen>

enum class Speed
{
    Fast = 10,
    Slow = 3
};

class PlayerParameters
{
public:
    PlayerParameters();
    qreal _screenHeight;
    qreal _height;
    qreal _width;
    qreal _gravity;
    qreal _stepY;
    qreal _posY;
    const qreal _posX = 100;
    qreal _stepX = int(Speed::Fast);
    void setSpeed(Speed speed);
    Speed getSpeed();
    ~PlayerParameters();
};

#endif // PLAYERPARAMETERS_H
