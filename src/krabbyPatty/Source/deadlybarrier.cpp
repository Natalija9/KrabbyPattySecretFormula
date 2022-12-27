#include "Headers/deadlybarrier.h"
#include <iostream>

DeadlyBarrier::DeadlyBarrier() = default;

void DeadlyBarrier::advance(int phase) {
  if (!phase)
    return;

  move();
}
DeadlyBarrier::~DeadlyBarrier() = default;
