#ifndef SLOWINGTILE_H
#define SLOWINGTILE_H

#include "tile.h"

class SlowingTile: public Tile
{
public:
     SlowingTile(qreal playerWidth, QString imagePath);
    void changeSpeed(PlayerParameters *playerParameters) override;
};

#endif // SLOWINGTILE_H
