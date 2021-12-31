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
    qreal _stepX = int(Speed::Fast);
    const qreal _posX = 100;

    void getScreenHeight();
    void calculateScalingParameters();
    void setStepFromSpeed(Speed speed);
    Speed getSpeedFromStep();
    ~PlayerParameters();
};

#endif // PLAYERPARAMETERS_H
