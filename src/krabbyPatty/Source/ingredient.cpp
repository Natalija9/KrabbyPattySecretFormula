#include "Headers/ingredient.h"
#include "Headers/score.h"
#include <QGraphicsScene>

extern Score *score;

Ingredient::Ingredient(qreal playerWidth, QString imagePath)
{
    qreal width = playerWidth * 0.6;
    qreal height = width * 0.9;
    setPixmap(QPixmap(imagePath).scaled(width, height));
}

void Ingredient::collect(){
    score->increase();
    scene()->removeItem(this);
    delete this;
}
Ingredient::~Ingredient(){

}
