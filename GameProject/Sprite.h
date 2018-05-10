#ifndef SPRITE_H_
#define SPRITE_H_

#include "TextureManager.h"

class Sprite
{
public:
    Sprite(const char* fileName = "");
    ~Sprite();

    double angle = 0;

    SDL_Rect srcRect, dstRect;
    SDL_Texture* texture;
    SDL_Point anchorPoint;
    SDL_RendererFlip flip = SDL_FLIP_NONE;

    void attr(const float scale, const float angle);
    void render();
    void loadFrame(const char* fileName);
    void setPosition(const int x, const int y);

private:
};

#endif // SPRITE_H_
