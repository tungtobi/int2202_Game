#include "Layer.h"
#include "Player.h"
#include "Fruit.h"

Layer::Layer()
{
    Layer::player = new Player();
    Layer::fruit = new Fruit();
    addFruit(fruit);
}

void Layer::addFruit(Fruit* f)
{
    Layer::fruits.push_back(f);
}

void Layer::update()
{
    Layer::player->update();
    for (Fruit* f : Layer::fruits)
    {
        f->update();
    }
    render();
}

void Layer::render()
{
    SDL_RenderClear(Game::renderer);
    Layer::player->sprite->render();
    for (Fruit* f : Layer::fruits)
    {
        f->sprite->render();
    }
    SDL_RenderPresent(Game::renderer);
}

Layer::~Layer()
{

}


