#include "Fruit.h"
#include <cstdlib>
#include <time.h>
#include <math.h>
#include "Layer.h"
#include <random>

extern Layer* layer;

int Fruit::generateRandom(int width)
{
    return rand() % width + 1;
}

Fruit::Fruit()
{
    srand(time(0));

    int type = generateRandom(2);

    switch (type)
    {
    case 1:
        sprite = new Sprite("res/fruit1.png");
        break;
    case 2:
        sprite = new Sprite("res/fruit_2.png");
        break;
    }

    w = sprite->dstRect.w;
    h = sprite->dstRect.h;

    x = generateRandom(SCREEN_WIDTH);
    y = -50;
}

void Fruit::checkOutsideLayer()
{
    if (y + h / 2 > SCREEN_HEIGHT)
    {
        layer->removeFruit(this);
    }
}

void Fruit::checkCaught(Player* player)
{
    if (player->y - y >= 0 && player->y - y <= (h + player->h) / 2 && abs(player->x - x) <= player->w / 2)
    {
        layer->removeFruit(this);
        layer->score++;
        layer->updateScore();
    }

}

void Fruit::update()
{
    dt += 0.2;

    sprite->angle++;

    y = -50 + speed * dt + acceleration * dt * dt / 2;

    sprite->dstRect.x = x - w / 2;
    sprite->dstRect.y = y - h / 2;

    checkOutsideLayer();

}

Fruit::~Fruit()
{
    SDL_DestroyTexture(sprite->texture);
    delete sprite;
}
