#include "Layer.h"
#include <algorithm>
#include <cstdlib>

Layer::Layer()
{
    initBackground();
    player = new Player();
    scoreLabel = new Text("res/tt0524m_.ttf", 40);
    timeLabel = new Text("res/tt0524m_.ttf", 40);
    updateScore();
}

void Layer::initBackground()
{
    background = new Sprite("res/background.png");
}

void Layer::addFruit(Fruit* f)
{
    fruits.push_back(f);
}

void Layer::removeFruit(Fruit* f)
{
    fruits.erase(std::remove(fruits.begin(), fruits.end(), f));
    f->~Fruit();

    delete f;
}

void Layer::renderSprite()
{
    player->sprite->render();
    for (Fruit* f : fruits)
    {
        if (f != NULL)
            f->sprite->render();
    }
}

void Layer::update()
{
    director.update();

    player->update();

    for (Fruit* f : Layer::fruits)
    {
        if (f != NULL)
        {
            f->update();
            f->checkCaught(player);
        }
    }

    updateTime();

    render();
}

void Layer::updateScore()
{
    scoreLabel->para = convertIntToStr(score);
    scoreLabel->initTexture();
}

void Layer::updateTime()
{
    timeLabel->para = convertIntToStr(time - SDL_GetTicks() / 1000) + 's';
    timeLabel->initTexture();
}

void Layer::render()
{
    SDL_RenderClear(Game::renderer);
    if (background != NULL)
    {
        background->render();
    }
    scoreLabel->render(40,  40);
    timeLabel->render(SCREEN_WIDTH / 2, 40);
    renderSprite();

    SDL_RenderPresent(Game::renderer);
}

Layer::~Layer()
{

}


