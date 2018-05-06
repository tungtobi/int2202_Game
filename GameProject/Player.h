#ifndef PLAYER_H_
#define PLAYER_H_

#include "Game.h"
#include "Animation.h"
#include "Resources.h"
//#include "Rock.h"

class Player
{
public:
    Player(const int type);
    ~Player();

    int id, x, y, w, h;
    float scale = 1;

    Animation* animation;

    void update();
    void render();
    void getStuck();
    void removeRock();
private:
    int speed = 0;
    Resources res{BLACK_PIG};
    Uint32 timeStuck = 0;
    bool isMoveLeft;

    bool isStuck();
    void listenEventFromKeyboard();
    bool isOutsideLayer();
    //Rock* rock;
};

#endif // PLAYER_H_
