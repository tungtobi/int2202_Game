#ifndef TEXTUREMANAGER_H_
#define TEXTUREMANAGER_H_

#include "Game.h"

class TextureManager
{
public:
    static SDL_Texture* LoadTexture(const char* fileName);
    static void drawSprite(SDL_Texture* texture, SDL_Rect src, SDL_Rect dst);
};

#endif // TEXTUREMANAGER_H_


