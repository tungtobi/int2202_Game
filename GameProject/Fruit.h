#ifndef FRUIT_H_
#define FRUIT_H_

#include "Game.h"

class Fruit
{
public:
    Fruit();
    ~Fruit();

    int x, y, speed = 1;
    int w = 33, h = 33;
    float scale = 1, angle = 0;

    static Sprite* sprite;

    void update();

private:
    bool isOutsideLayer();
    int getRandomPositionX(int width);
};

#endif // FRUIT_H_

