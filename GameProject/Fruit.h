#ifndef FRUIT_H_
#define FRUIT_H_

#include "Game.h"
#include "Player.h"

class Fruit
{
public:
    Fruit();
    ~Fruit();

    int x, y, w, h;
    float scale = 1;

    int acceleration = 3, speed = 1;

    Sprite* sprite;

    void update();
    void checkCaught(Player* player);

private:
    float dt = 0;
    void checkOutsideLayer();
    int generateRandom(int width);
};

#endif // FRUIT_H_

