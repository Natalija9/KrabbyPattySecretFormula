#include "life.h"

Life::Life()
{
    setPixmap(QPixmap(":images/star.png").scaled(50,50));
    setPos(180, 150);
}
