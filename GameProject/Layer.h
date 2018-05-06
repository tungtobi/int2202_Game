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
    Player player{BLACK_PIG};

    Sprite background{"res/background.png"};

    unsigned int score = 0;
    double time = 30;
    bool isPause = false;

    void addFruit(Fruit* f);
    void removeFruit(Fruit* f);
    void update();
    void render();
    void updateScore();

private:
    Text scoreLabel{BOLD, 24};
    Text timeLabel{BOLD, 30};

    Director director;

    void updateTime();
    void renderSprite();
};

#endif // LAYER_H_
