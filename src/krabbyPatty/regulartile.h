#ifndef REGULARTILE_H
#define REGULARTILE_H

#include "item.h"
#include "tile.h"

class RegularTile : public Tile
{
public:
    RegularTile(qreal playerWidth, QString imagePath);
    void changeSpeed(Player *player) override;
};

#endif // REGULARTILE_H
