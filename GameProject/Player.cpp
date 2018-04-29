#include "Player.h"
#include "Layer.h"

extern Layer* layer;

Player::Player()
{
    sprite = new Sprite("res/player.png");
    w = sprite->dstRect.w;
    h = sprite->dstRect.h;
    x = SCREEN_WIDTH / 2;
    y = SCREEN_HEIGHT - 100;
}

void Player::listenEventFromKeyboard()
{
    if (Game::event.type == SDL_KEYDOWN)
    {
        switch (Game::event.key.keysym.sym)
        {
        case SDLK_LEFT:
            if (!isOutsideLayer() && !isStuck())
            {
                sprite->flip = SDL_FLIP_HORIZONTAL;
                speed = -5;
            }
            break;
        case SDLK_RIGHT:
            if (!isOutsideLayer() && !isStuck())
            {
                sprite->flip = SDL_FLIP_NONE;
                speed = 5;
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
    if (x + w / 2 > SCREEN_WIDTH)
    {
        x = SCREEN_WIDTH - w / 2;
    }
    else if (x - w / 2 < 0)
    {
        x = w / 2;
    }

    return false;
}

void Player::update()
{
    x += speed;
    sprite->dstRect.x = x - w / 2;
    sprite->dstRect.y = y - h / 2;
    w = sprite->dstRect.w;
    h = sprite->dstRect.h;

    listenEventFromKeyboard();
}

void Player::getStuck()
{
    speed = 0;
    sprite->loadFrame("res/playerHurt.png");
    timeStuck = SDL_GetTicks();
}

bool Player::isStuck()
{
    if (SDL_GetTicks() - timeStuck >= 3000)
    {
        timeStuck = 0;
        sprite->loadFrame("res/player.png");
        return false;
    }
    else if (timeStuck > 0)
    {
        return true;
    }
}

Player::~Player()
{

}
