#ifndef MAP_H_
#define MAP_H_

#include "Game.h"

class Map
{
public:
    Map();
    ~Map();

    void loadMap();
    void drawMap();

private:
    SDL_Rect src, dst;
    SDL_Texture* dirt;
    SDL_Texture* grass;
    SDL_Texture* water;

};

#endif // MAP_H_
