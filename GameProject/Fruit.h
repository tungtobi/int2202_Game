#ifndef FRUIT_H_
#define FRUIT_H_

#include "Game.h"
#include "Player.h"

enum FruitType
{
    PEAR = 1,
    STRAWBERRY,
    PEACH,
    ROCK,
    MEDICINE,
    MUSHROOM
};

class Fruit
{
public:
    Fruit();
    ~Fruit();

    int x, y, w, h;
    float scale = 1;

    int acceleration = 3, speed = 1;

    Sprite sprite;

    void update();
    void checkCaught(Player& player);

private:
    FruitType type;
    float dt = 0;
    void checkOutsideLayer();
    int generateRandom(int width);
    std::string loadFileName(FruitType type);
    double getDistance(const Player& player);
};

#endif // FRUIT_H_

