#ifndef DIRECTOR_H_
#define DIRECTOR_H_

#include "Game.h"

class Director
{
public:
    Director();
    ~Director();

    void update();
private:
    int dt = 0;
    void createFruit();
};

#endif // DIRECTOR_H_
