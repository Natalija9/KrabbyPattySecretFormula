#include "Headers/evilspongebob.h"

EvilSpongeBob::EvilSpongeBob(qreal playerWidth) {
  width = playerWidth;
  height = width;
  setPixmap(QPixmap(":/images/EvilSpongeBob.png").scaled(width, height));

  this->left = true;
}

void EvilSpongeBob::move() {
  stepForward();
  changeVerticalDirectionIfNeeded();
  changeHorizontalDirectionIfNeeded();
}

void EvilSpongeBob::stepForward() {
  setPos(x() - move_x, y() - move_y);
  steps++;
}

void EvilSpongeBob::changeVerticalDirectionIfNeeded() {
  if (steps % changeVertical == 0) {
    move_y = -move_y;
  }
}

void EvilSpongeBob::changeHorizontalDirectionIfNeeded() {
  if (steps == max_steps) {
    left = !left;
    steps = 0;
    move_x = -move_x;
  }
}

qreal EvilSpongeBob::getHeight() { return height; }

qreal EvilSpongeBob::getWidth() { return width; }

EvilSpongeBob::~EvilSpongeBob() {}
