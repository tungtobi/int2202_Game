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
        createFruit();
        dt = 0;
    }
    else dt += 1;
}

void Director::createFruit()
{
    Fruit* fruit = new Fruit();
    layer->addFruit(fruit);
}

Director::~Director()
{

}
