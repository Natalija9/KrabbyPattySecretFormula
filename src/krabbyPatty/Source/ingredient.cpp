#include "ingredient.h"
#include "score.h"


extern Score *score;

Ingredient::Ingredient(qreal playerWidth, QString imagePath)
{
    qreal width = playerWidth * 0.6;
    qreal height = width * 0.9;
    setPixmap(QPixmap(imagePath).scaled(width, height));
}

void Ingredient::collect(){
    score->increase();
}