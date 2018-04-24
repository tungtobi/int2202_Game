#include "Layer.h"
#include "Player.h"
#include "Fruit.h"

Layer::Layer()
{
    Player* player = new Player();
    addChild(player->sprite);

    Fruit* fruit = new Fruit();
    addChild(fruit->sprite);
}

void Layer::addChild(Sprite* child)
{
    Layer::childs.push_back(child);
}

void Layer::render()
{
    SDL_RenderClear(Game::renderer);
    for (Sprite* spr : Layer::childs)
    {
        spr->render();
    }
    SDL_RenderPresent(Game::renderer);
}

Layer::~Layer()
{

}


