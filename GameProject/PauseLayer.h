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
    Text pauseLabel{BOLD, 150};
    void render();
};

#endif // PAUSELAYER_H_
