#include "Player.h"
#include "Layer.h"

extern Layer* layer;

Player::Player(const int type)
{
    id = type;

    animation = new Animation(res.normal);

    w = animation->sprite->dstRect.w;
    h = animation->sprite->dstRect.h;

    x = SCREEN_WIDTH / 2;
    y = SCREEN_HEIGHT - 105;
}

void Player::listenEventFromKeyboard()
{
    if (Game::event.type == SDL_KEYDOWN)
    {
        switch (Game::event.key.keysym.sym)
        {
        case SDLK_LEFT:
            if (!isOutsideLayer() && !isStuck() && !layer->isPause)
            {
                animation->sprite->flip = SDL_FLIP_HORIZONTAL;
                speed = -5;
            }
            break;
        case SDLK_RIGHT:
            if (!isOutsideLayer() && !isStuck() && !layer->isPause)
            {
                animation->sprite->flip = SDL_FLIP_NONE;
                speed = 5;
            }
            break;
        case SDLK_p:
            layer->isPause = !layer->isPause;
            speed = 0;
            break;
        case SDLK_UP:

            break;
        }

        if (speed != 0)
        {
            animation->runAnimation();
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

void Player::removeRock()
{
    /*
    if (rock)
    {
        delete rock;
        rock = NULL;
    }
    */
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
    animation->sprite->setPosition(x, y);
    listenEventFromKeyboard();

    /*
    if (rock)
    {
        rock->update();
    }
    */
}

void Player::render()
{
    animation->sprite->render();
    /*
    if (rock)
    {
        rock->sprite->render();
    }
    */
}

void Player::getStuck()
{
    speed = 0;
    animation->sprite->loadFrame(res.hurted);
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
    delete animation;

    //if (rock)
        //delete rock;
    std::cout << "Delete Player" << std::endl;
}
