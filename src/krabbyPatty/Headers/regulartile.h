#ifndef REGULARTILE_H
#define REGULARTILE_H

#include "item.h"
#include "tile.h"

class RegularTile : public Tile {
public:
  RegularTile(qreal playerWidth, QString imagePath);
  void changeSpeed(PlayerParameters* playerParameters) override;
  ~RegularTile();
};

#endif // REGULARTILE_H
