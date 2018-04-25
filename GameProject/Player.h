#ifndef PLAYER_H_
#define PLAYER_H_

#include "Game.h"

class Player
{
public:
    Player();
    ~Player();

    int x, y, speed = 0;
    int w, h;
    float scale = 1, angle = 0;

    Sprite* sprite;

    void update();

private:
    void listenEventFromKeyboard();
    bool isOutsideLayer();
};


#endif // PLAYER_H_
