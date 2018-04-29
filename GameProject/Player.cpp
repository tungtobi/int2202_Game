#include "Player.h"
#include "Layer.h"

extern Layer* layer;

Player::Player()
{
    animation = new Animation("res/playerAnimation");
    w = animation->sprite->dstRect.w;
    h = animation->sprite->dstRect.h;

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
                animation->sprite->flip = SDL_FLIP_HORIZONTAL;
                animation->runAnimation();
                speed = -5;
            }
            break;
        case SDLK_RIGHT:
            if (!isOutsideLayer() && !isStuck())
            {
                animation->sprite->flip = SDL_FLIP_NONE;
                animation->runAnimation();
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
        case SDLK_RIGHT:
            speed = 0;
            if (!isStuck())
            {
                animation->initNormalSprite();
            }
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
    animation->sprite->dstRect.x = x - w / 2;
    animation->sprite->dstRect.y = y - h / 2;

    listenEventFromKeyboard();
}

void Player::getStuck()
{
    speed = 0;
    animation->sprite->loadFrame("res/playerHurt.png");
    timeStuck = SDL_GetTicks();
}

bool Player::isStuck()
{
    bool result;
    if (SDL_GetTicks() - timeStuck >= 3000)
    {
        timeStuck = 0;
        result = false;
    }
    else if (timeStuck > 0)
    {
        result = true;
    }
    return result;
}

Player::~Player()
{

}
