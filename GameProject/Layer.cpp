#include "Layer.h"
#include "Player.h"
#include "Fruit.h"
#include <algorithm>

Layer::Layer()
{
    player = new Player();
}

void Layer::initBackground()
{
    background = new Sprite("res/background.png");
    //background->attr(1, 0);
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

void Layer::render()
{
    SDL_RenderClear(Game::renderer);
    if (background != NULL)
    {
        background->render();
    }
    renderSprite();
    SDL_RenderPresent(Game::renderer);
}

Layer::~Layer()
{

}


