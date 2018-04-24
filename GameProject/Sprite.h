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

    int x, y;

    SDL_Texture* texture;
    SDL_Rect srcRect;
    SDL_Rect dstRect;

    void attr
    (
        const int _w,
        const int _h,
        const float scale,
        const float angle
    );

    void update();
    void render();

private:

};

#endif // SPRITE_H_
