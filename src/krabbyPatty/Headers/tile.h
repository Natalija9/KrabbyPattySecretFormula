#ifndef TILE_H
#define TILE_H

#include "playerparameters.h"
#include <QGraphicsPixmapItem>

class Tile : QObject, public QGraphicsPixmapItem {
public:
  Tile();
  virtual void changeSpeed(PlayerParameters* playerParameters) = 0;
  ~Tile();
};

#endif // TILE_H
