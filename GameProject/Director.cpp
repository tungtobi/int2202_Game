#include "Director.h"
#include "Fruit.h"
#include "Layer.h"

extern Layer* layer;

Director::Director()
{

}

void Director::update()
{
    if (dt >= 50)
    {
        Game::mixManager.playSoundEffect(DROP_SOUND);
        createFruit();
        dt = 0;
    }
    else if (!layer->isPause)
    {
        dt++;
    }
}

void Director::createFruit()
{
    if (layer)
    {
        Fruit* fruit = new Fruit();
        layer->addFruit(fruit);
    }
}

Director::~Director()
{

}
