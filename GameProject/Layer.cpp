#include "Layer.h"
#include "Player.h"
#include "Fruit.h"
#include <algorithm>
#include <cstdlib>

Layer::Layer()
{
    player = new Player();
    scoreLabel = new Text("res/tt0524m_.ttf", 400);
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

    render();
}

void Layer::updateScore()
{
    scoreLabel->para = convertIntToStr(score);
    scoreLabel->initTexture();
    std::cout << "Score: " << convertIntToStr(score) << std::endl;
}

void Layer::render()
{
    SDL_RenderClear(Game::renderer);
    if (background != NULL)
    {
        background->render();
    }
    scoreLabel->render(SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2);
    renderSprite();

    SDL_RenderPresent(Game::renderer);
}

Layer::~Layer()
{

}


