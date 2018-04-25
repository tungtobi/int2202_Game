#ifndef PLAYER_H_
#define PLAYER_H_

#include "Game.h"

class Player
{
public:
    Player();
    ~Player();

    int x, y, w, h;
    int speed = 0;
    float scale = 1;

    Sprite* sprite;

    void update();

private:
    void listenEventFromKeyboard();
    bool isOutsideLayer();
};


#endif // PLAYER_H_
