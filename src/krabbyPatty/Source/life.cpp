#include "Headers/life.h"
#include "Headers/score.h"
#include <QGraphicsScene>

extern Score* score;

Life::Life(qreal playerWidth) {
  qreal width = playerWidth * 0.5;
  qreal height = width;
  setPixmap(QPixmap(":images/star.png").scaled(width, height));
}

void Life::collect() {
  score->addLife();
  scene()->removeItem(this);
  delete this;
}
Life::~Life() {}
