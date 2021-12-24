#include "deadlybarrier.h"
#include <iostream>

DeadlyBarrier::DeadlyBarrier() {}

void DeadlyBarrier::advance(int phase) {
    if(!phase)
        return;

    move();
}
