#include "ingredient.h"

Ingredient::Ingredient(qreal playerWidth)
{
    qreal width = playerWidth * 0.6;
    qreal height = width;
    setPixmap(QPixmap(":images/bun.png").scaled(width, height));
}
