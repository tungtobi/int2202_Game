#ifndef FRUIT_H_
#define FRUIT_H_

#include "Game.h"
#include "Player.h"

class Fruit
{
public:
    Fruit();
    ~Fruit();

    int x, y;
    int acceleration = 1, speed = 1;
    int w = 33, h = 33;
    float scale = 1, angle = 0;

    Sprite* sprite;

    void update();
    void checkCaught(Player* player);

private:
    float dt = 0;
    void checkOutsideLayer();
    int generateRandom(int width);
};

#endif // FRUIT_H_

