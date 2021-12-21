#include "deadlybarrier.h"
#include <iostream>

DeadlyBarrier::DeadlyBarrier()
{/*
    qreal width = playerWidth * 0.5;
    qreal height = width;
    setPixmap(QPixmap(imagePath).scaled(width, height));*/
}

void DeadlyBarrier::advance(int phase) {
    if(!phase)
        return;

    move();

    //std::cout << "radi :)" << std::endl;
    //setPos(x() + 0.5, y());

}


//void Player::advance(int phase)
//{
//    if(!phase){
//        return;
//    }
//    if(isDead()){
//        level->death();
//    }
//    else{
//        level->view->centerOn(this);
//    }
//    if(m_canMove)
//    {
//        walk();
//    }
//    jump();
//    detectCollision();
//}
