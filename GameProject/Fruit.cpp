#include "Fruit.h"
#include <cstdlib>
#include <time.h>
#include <math.h>
#include "Layer.h"
#include <random>
#include <string>

#define MAX_TYPE 4

extern Layer* layer;

int Fruit::generateRandom(int width)
{
    return rand() % width + 1;
}

std::string Fruit::loadFileName(int type)
{
    std::string path1 = "res/fruit",
    path2 = "0",
    path3 = ".png";
    path2[0] = char(type + '0');
    return path1 + path2 + path3;
}

Fruit::Fruit()
{
    srand(time(0));

    type = generateRandom(MAX_TYPE);
    std::string path = loadFileName(type);

    sprite = new Sprite(path.c_str());

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

        switch (type)
        {
        case 1:
        case 2:
        case 3:
            layer->score++;
            break;
        case 4:
            layer->score /= 2;
            break;
        }

        layer->updateScore();
    }

}

void Fruit::update()
{
    dt += 0.2;

    sprite->angle = acceleration * dt * dt / 6;

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
