#ifndef SPRITE_H_
#define SPRITE_H_

#include <iostream>
#include <SDL2/SDL.h>
#include <SDL_image.h>
#include "TextureManager.h"

class Sprite
{
public:
    Sprite(const char* fileName);
    ~Sprite();

    int x = 0, y = 0;

    SDL_Texture* texture;
    SDL_Rect srcRect, dstRect;

    double angle = 0;

    SDL_Point anchorPoint;

    void attr(const float scale, const float angle);

    void update();
    void render();

private:

};

#endif // SPRITE_H_
