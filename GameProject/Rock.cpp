#include "Rock.h"
#include "Resources.h"
#include <cmath>
#include "Layer.h"

extern Layer* layer;

Rock::Rock(const int id, const int _x, const int _y)
{
    type = id;
    sprite = new Sprite("res/fruit4.png");

    w = sprite->dstRect.w;
    h = sprite->dstRect.h;

    x = _x;
    y = _y;
    y0 = y;

    sprite->setPosition(x, y);
}

void Rock::update()
{
    /*
    if (!Game::isPause)
    {
        dt++;
    }

    sprite->angle = abs(acceleration) * dt * dt / 2;

    if (dt >= 12 && acceleration < 0)
    {
        acceleration = 1;
        y0 = y;
        dt = 0;
    }

    y = y0 + acceleration * dt * dt / 2;
    x += speed;

    sprite->setPosition(x, y);

    checkOutsideLayer();
    */
}

/*
void Rock::checkCollision(Player* player)
{
    if (2 * abs(x - player->x) <= w + player->w
        && 2 * abs(y - player->y) <= h + player->h)
    {
        player->getStuck();
    }
}
*/

void Rock::checkOutsideLayer()
{
    if (x + w / 2 <= 0 || x - w / 2 >= SCREEN_WIDTH || y + h / 2 > SCREEN_HEIGHT - 70)
    {
        layer->player.removeRock();
    }
}

Rock::~Rock()
{
    if (sprite)
        delete sprite;
    std::cout << "Rock removed" << std::endl;
}
