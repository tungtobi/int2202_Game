#ifndef COLLISIONDETECTION_H_
#define COLLISIONDETECTION_H_

#include "Game.h"

class CollisionDetection
{
    SDL_Rect collider;
    std::string tag;

    void init();
};

#endif // COLLISIONDETECTION_H_
