#ifndef INGREDIENT_H
#define INGREDIENT_H

#include "item.h"
#include <QObject>

class Ingredient : public Item
{
public:
    Ingredient();
    friend int Item::collect();

    //virtual ~Ingredient();
private:
    int number_of_points;
};

#endif // INGREDIENT_H
