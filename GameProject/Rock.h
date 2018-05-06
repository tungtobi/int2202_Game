#ifndef ROCK_H_
#define ROCK_H_

#include "Game.h"
#include "Sprite.h"

class Rock
{
public:
    Rock(const int id, const int _x, const int _y);
    ~Rock();

    Sprite* sprite;
    int speed = 6;
    void update();
private:
    int type;
    int dt = 0;
    int x, y, y0, w, h;
    int acceleration = -1;
    void checkOutsideLayer();
    //void checkCollision(Player* player);
};

#endif // ROCK_H_
