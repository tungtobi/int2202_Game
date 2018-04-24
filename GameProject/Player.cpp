#include "Player.h"

Player::Player()
{
    sprite = new Sprite("res/player.png");
    sprite->attr(w, h, scale, angle);
    x = 400;
    y = 500;
}

void Player::listenEventFromKeyboard()
{
    if (Game::event.type == SDL_KEYDOWN)
    {
        switch (Game::event.key.keysym.sym)
        {
        case SDLK_LEFT:
            if (!isOutsideLayer())
            {
                speed = -1;
            }
            break;
        case SDLK_RIGHT:
            if (!isOutsideLayer())
            {
                speed = 1;
            }
            break;
        }
    }

    if (Game::event.type == SDL_KEYUP)
    {
        switch (Game::event.key.keysym.sym)
        {
        case SDLK_LEFT:
            speed = 0;
            break;
        case SDLK_RIGHT:
            speed = 0;
            break;
        }
    }
}

bool Player::isOutsideLayer()
{
    if (x + w / 2 > 800)
    {
        x = 800 - w / 2;
    }
    else if (x - w / 2 < 0)
    {
        x = w / 2;
    }
}

void Player::update()
{
    x += speed;
    sprite->dstRect.x = x - w / 2;
    sprite->dstRect.y = y - h / 2;

    //sprite->render();

    listenEventFromKeyboard();
}

Player::~Player()
{

}
