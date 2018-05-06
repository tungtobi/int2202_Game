#include "Explosion.h"
#include "Layer.h"
#include <algorithm>

extern Layer* layer;

Explosion::Explosion()
{
    animation = new Animation("res/explosion");
    animation->frameNumber = 5;
    std::cout << "init" << std::endl;
}

void Explosion::update()
{
    animation->runAnimation();

    if (animation->keyFrame >= animation->frameNumber)
    {
        layer->animates.erase(std::remove(layer->animates.begin(), layer->animates.end(), this));
        std::cout << "delete" << std::endl;
        delete this;
    }
}

Explosion::~Explosion()
{

    delete animation;
}
