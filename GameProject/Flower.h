#ifndef FLOWER_H_
#define FLOWER_H_

#include "Game.h"
#include "Animation.h"
#include "Player.h"

class Flower
{
public:
    Flower();
    Animation animate;
    void checkCaught(Player& player);
    void update();
    void render();
};

#endif // FLOWER_H_
