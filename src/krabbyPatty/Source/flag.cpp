#include "Headers/flag.h"


Flag::Flag(Level* parent, qreal playerWidth) {
  lvl = parent;
  qreal width = playerWidth * 0.7;
  qreal height = width * 2;
  setPixmap(QPixmap(":images/flag.png").scaled(width, height));
}

void Flag::collect() { lvl->finishLevel(MessageText::LevelCompleted); }

Flag::~Flag() = default;
