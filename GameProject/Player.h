#ifndef PLAYER_H_
#define PLAYER_H_

#include "Game.h"
#include "Animation.h"
#include "Resources.h"

class Player
{
public:
    Player(PlayerType type);
    ~Player();

    int id, x, y, w, h;
    float scale = 1;
    unsigned int score = 0;

    Animation animation;

    void update();
    void render();
    void getStuck();
    void removeRock();
    bool isStuck();
private:
    int speed = 0;
    Resources res;
    Uint32 timeStuck = 0;
    bool isMoveRight = true;

    void listenEventFromKeyboard(const SDL_Keycode moveRight, const SDL_Keycode moveLeft);
    bool isOutsideLayer();
};

#endif // PLAYER_H_
