#ifndef EXPLOSION_H_
#define EXPLOSION_H_

#include "Animation.h"

class Explosion
{
public:
    Explosion();
    ~Explosion();
    void update();

    Animation* animation;
};

#endif // EXPLOSION_H_
