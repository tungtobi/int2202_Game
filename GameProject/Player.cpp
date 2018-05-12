#include "Player.h"
#include "Layer.h"
#include "Mixer.h"
#include <cmath>

extern Layer* layer;

Player::Player(PlayerType type)
{
    id = type;
    res.setType(type);

    animation.loadImage(res.normal);

    w = animation.sprite.dstRect.w;
    h = animation.sprite.dstRect.h;

    x = SCREEN_WIDTH / 2;
    y = SCREEN_HEIGHT - 105;
}

void Player::listenEventFromKeyboard(const SDL_Keycode moveRight, const SDL_Keycode moveLeft)
{
    SDL_Keycode key = Game::event.key.keysym.sym;

    if (Game::event.type == SDL_KEYDOWN)
    {
        if (key == moveLeft)
        {
            if (!isOutsideLayer() && !isStuck() && !layer->isPause)
            {
                isMoveRight = false;
                animation.sprite.flip = SDL_FLIP_HORIZONTAL;
                speed = -5;
            }
        }
        else if (key == moveRight)
        {
            if (!isOutsideLayer() && !isStuck() && !layer->isPause)
            {
                isMoveRight = true;
                animation.sprite.flip = SDL_FLIP_NONE;
                speed = 5;
            }
        }
        else if (key == SDLK_p)
        {
            if (id == BLACK_PIG)
            {
                layer->isPause = !layer->isPause;
            }
            speed = 0;
        }

        if (speed != 0)
        {
            animation.runAnimation();
        }
    }

    if (Game::event.type == SDL_KEYUP)
    {
        if (key == moveLeft || key == moveRight)
        {
            speed = 0;
            if (!isStuck())
            {
                animation.initNormalSprite();
            }
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
    if (!isOutsideLayer())
    {
        x += speed;
    }

    animation.sprite.setPosition(x, y);

    if (id == BLACK_PIG)
    {
        listenEventFromKeyboard(SDLK_RIGHT, SDLK_LEFT);
    }
    else
    {
        listenEventFromKeyboard(SDLK_LALT, SDLK_LSHIFT);
    }
}

void Player::render()
{
    animation.sprite.render();
}

void Player::getStuck()
{
    speed = 0;
    animation.sprite.loadFrame(res.hurted);
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
    std::cout << "Delete Player" << std::endl;
}
