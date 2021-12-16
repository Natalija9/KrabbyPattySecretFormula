#include "ingredient.h"

Ingredient::Ingredient(qreal playerWidth, QString imagePath)
{
    qreal width = playerWidth * 0.6;
    qreal height = width;
    setPixmap(QPixmap(imagePath).scaled(width, height));
}
