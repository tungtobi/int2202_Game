#ifndef LAYER_H_
#define LAYER_H_

#include "Game.h"
#include "Player.h"
#include "Fruit.h"
#include <vector>

class Layer
{
public:
    Layer();
    ~Layer();

    std::vector <Fruit*> fruits;
    Player* player;
    Fruit* fruit;

    void addFruit(Fruit* f);
    void update();
    void render();
};

#endif // LAYER_H_
