#ifndef LAYER_H_
#define LAYER_H_

#include "Game.h"
#include <vector>

class Layer
{
public:
    Layer();
    ~Layer();

    std::vector <Sprite*> childs;

    void addChild(Sprite* child);
    void render();
};

#endif // LAYER_H_
