#include "Layer.h"
#include <algorithm>
#include <cstdlib>

Layer::Layer()
{
    initBackground();
    player = new Player();
    scoreLabel = new Text("res/Maplestory Bold.ttf", 24);
    timeLabel = new Text("res/Maplestory Bold.ttf", 30);
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
    player->animation->sprite->render();
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
    int timeLeft = time - SDL_GetTicks() / 1000;
    timeLabel->para = convertIntToStr(timeLeft) + 's';
    if (timeLeft <= 10)
    {
        timeLabel->color = {255, 0, 0};
    }
    timeLabel->initTexture();
}

void Layer::render()
{
    SDL_RenderClear(Game::renderer);
    background->render();
    renderSprite();
    scoreLabel->render(60, 40, LEFT_ALIGN);
    timeLabel->render(SCREEN_WIDTH / 2, 40, CENTER_ALIGN);

    SDL_RenderPresent(Game::renderer);
}

Layer::~Layer()
{

}


