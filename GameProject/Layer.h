#ifndef LAYER_H_
#define LAYER_H_

#include "Player.h"
#include "Fruit.h"
#include "TextManager.h"
#include <vector>
#include "Director.h"
#include "Flower.h"

class Layer
{
public:
    Layer(const bool _isMultyPlayer = false);
    ~Layer();

    std::vector <Fruit*> fruits;
    Player player{BLACK_PIG}, player2{PINK_PIG};

    double time = 30;

    bool isPause = false;
    bool isMultyPlayer;

    void addFruit(Fruit* f);
    void removeFruit(Fruit* f);
    void addFlower(const int type);
    void removeFlower(Flower* f);
    void update();
    void updateScore(const Player& player);

private:
    Text scoreLabel{BOLD, 24};
    Text timeLabel{BOLD, 30};
    Text score2Label{BOLD, 24};
    Sprite background{"res/background.png"};

    Director director;

    void updateTime();
    void updateFruit();

    void render();
    void renderSprite();
    void renderLabel();

    std::vector <Flower*> flowers;
};

#endif // LAYER_H_
