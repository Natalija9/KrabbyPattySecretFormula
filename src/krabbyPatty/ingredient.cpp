#include "ingredient.h"

Ingredient::Ingredient()
{
    setPixmap(QPixmap(":images/bun.png").scaled(50,50));
    setPos(400, 200);
}