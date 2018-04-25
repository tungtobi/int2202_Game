#ifndef LAYER_H_
#define LAYER_H_

#include "Player.h"
#include "Fruit.h"
#include "TextManager.h"
#include <vector>
#include "Director.h"

class Layer
{
public:
    Layer();
    ~Layer();

    std::vector <Fruit*> fruits;
    Player* player;

    Sprite* background;

    unsigned int score = 0;

    void addFruit(Fruit* f);
    void removeFruit(Fruit* f);
    void update();
    void render();
    void updateScore();

private:
    Text* scoreLabel;
    Director director;
    void renderSprite();
    void initBackground();
};

#endif // LAYER_H_
