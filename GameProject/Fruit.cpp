#include <cstdlib>
#include <time.h>
#include <math.h>
#include <random>
#include <string>
#include "Fruit.h"
#include "Layer.h"

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
    int maxType = 5 + ((layer->isMultyPlayer) ? 1 : 0);

    srand(time(0));
    type = generateRandom(maxType);

    std::string path = loadFileName(type);

    sprite.loadFrame(path.c_str());

    w = sprite.dstRect.w;
    h = sprite.dstRect.h;

    if (type != 4)
    {
        x = generateRandom(SCREEN_WIDTH);
    }
    else
    {
        speed = 2;
        acceleration = 5;
        if (layer)
        {
            x = layer->player.x;
            if (layer->isMultyPlayer)
            {
                if (rand() % 2)
                {
                    x = layer->player.x;
                }
                else
                {
                    x = layer->player2.x;
                }
            }
        }
    }

    y = -50;
}

void Fruit::checkOutsideLayer()
{
    if (y + h / 2 > SCREEN_HEIGHT - 70)
    {
        if (layer)
        {
            layer->removeFruit(this);
        }
        Game::mixManager.playSoundEffect(BROKEN_SOUND);
    }
}

void Fruit::checkCaught(Player& player)
{
    if (layer)
        if (player.y - y >= 0 && player.y - y <= (h + player.h) / 2 && abs(player.x - x) <= player.w / 2)
        {
            layer->removeFruit(this);

            switch (type)
            {
            case 4:
                player.score /= 2;
                player.getStuck();
                break;
            case 5:
                layer->time += 5.0;
                Game::mixManager.playSoundEffect(EATING_SOUND);
                break;
            case 6:
                layer->addFlower(player.id);
                break;
            default:
                player.score++;
                Game::mixManager.playSoundEffect(EATING_SOUND);
                break;
            }

            layer->updateScore(player);
        }
}

void Fruit::update()
{
    if (!layer->isPause)
    {
        dt += 0.2;
    }

    sprite.angle = acceleration * dt * dt / 6;

    y = -50 + speed * dt + acceleration * dt * dt / 2;

    sprite.setPosition(x, y);

    checkOutsideLayer();

    if (layer->isMultyPlayer)
    {
        if (rand() % 2)
        {
            checkCaught(layer->player);
            checkCaught(layer->player2);
        }
        else
        {
            checkCaught(layer->player2);
            checkCaught(layer->player);
        }
    }
    else
    {
        checkCaught(layer->player);
    }
}

Fruit::~Fruit()
{
    std::cout << "Delete fruit" << std::endl;
}
