#include "Fruit.h"
#include <cstdlib>
#include <time.h>

const int SCREEN_WIDTH = 800;
const int SCREEN_HEIGHT = 600;

int Fruit::getRandomPositionX(int width)
{
    srand(time(NULL));
    int posX = rand() % width;

    return posX;
}

Fruit::Fruit()
{
    sprite = new Sprite("res/fruit.png");
    sprite->attr(w, h, scale, angle);

    x = getRandomPositionX(SCREEN_WIDTH);
    y = -50;
}

bool Fruit::isOutsideLayer()
{
    if (y + h / 2 > SCREEN_HEIGHT)
    {
        x = getRandomPositionX(SCREEN_WIDTH) / 2;
        std::cout << x << std::endl;
        y = -50;
        //return true;
    }
    //return false;
}

void Fruit::update()
{
    y += 1;
    sprite->dstRect.x = x - w / 2;
    sprite->dstRect.y = y - h / 2;

    isOutsideLayer();

}

Fruit::~Fruit()
{

}
