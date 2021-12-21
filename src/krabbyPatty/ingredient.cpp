#include "ingredient.h"
#include "score.h"

extern Score *score;

Ingredient::Ingredient(qreal playerWidth, QString imagePath)
{
    qreal width = playerWidth * 0.6;
    qreal height = width;
    setPixmap(QPixmap(imagePath).scaled(width, height));
}

void Ingredient::collect(){
    score->increase();
}
