#ifndef SPRITE_H_
#define SPRITE_H_

#include <iostream>
#include <SDL2/SDL.h>
#include <SDL_image.h>

class Sprite
{
public:
    int x, y;
    float scale, angle;

    SDL_Texture* image;

    SDL_Rect* srcR;
    SDL_Rect* dstRect;

    void getContentSize(const int _w, const int _h, const float scale);

};

#endif // SPRITE_H_
