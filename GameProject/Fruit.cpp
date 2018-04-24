#include "Fruit.h"
#include <cstdlib>
#include <ctime>

extern const int SCREEN_WIDTH = 800;
extern const int SCREEN_HEIGHT = 600;

int Fruit::getRandomPositionX(int width)
{
    srand(time(0));
    return rand() % (width - w) + w / 2;
}

Fruit::Fruit()
{
    sprite = new Sprite("res/fruit.png");
    sprite->attr(w, h, scale, angle);

    x = Fruit::getRandomPositionX(SCREEN_WIDTH);
    y = -50;
}

bool Fruit::isOutsideLayer()
{
    if (y + h / 2 > SCREEN_HEIGHT)
    {
        x = Fruit::getRandomPositionX(SCREEN_WIDTH);
        y = -50;
        return true;
    }
    return false;
}

void Fruit::update()
{
    y += speed;
    sprite->dstRect.x = x - w / 2;
    sprite->dstRect.y = y - h / 2;

    //sprite->render();

}

Fruit::~Fruit()
{

}
