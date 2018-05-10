#ifndef PAUSELAYER_H_
#define PAUSELAYER_H_

#include "Game.h"
#include "TextManager.h"
#include "Sprite.h"

class PauseLayer
{
public:
    PauseLayer();
    ~PauseLayer();
    void render();
private:
    Text pauseLabel{LIGHT, 12};
    Sprite background{"res/loadingScene.png"};
};

#endif // PAUSELAYER_H_
