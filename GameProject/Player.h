#ifndef PLAYER_H_
#define PLAYER_H_

#include "Game.h"
#include "Sprite.h"

class Player
{
public:
    Player();
    ~Player();

    int x, y, w, h;

    float scale = 1;

    Sprite* sprite;

    void update();
    void getStuck();

private:
    bool isStuck();
    void listenEventFromKeyboard();
    bool isOutsideLayer();
    bool isMoveLeft;
    int speed = 0;
    Uint32 timeStuck = 0;
};

#endif // PLAYER_H_
