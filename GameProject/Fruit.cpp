#include "Fruit.h"
#include <cstdlib>
#include <ctime>

int Fruit::getRandomPositionX(int width)
{
    srand(time(0));
    return rand() % (width - w) + w / 2;
}

Fruit::Fruit()
{
    sprite = new Sprite("res/fruit.png");
    sprite->attr(w, h, scale, angle);

    x = Fruit::getRandomPositionX(800);
    y = -50;
}

bool Fruit::isOutsideLayer()
{
    if (y + h / 2 > 600)
    {
        x = Fruit::getRandomPositionX(800);
        y = -50;
        return false;
    }
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
