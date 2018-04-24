#include "TextureManager.h"

SDL_Texture* TextureManager::LoadTexture(const char* fileName)
{
    SDL_Surface* tmpSurface = IMG_Load(fileName);
    SDL_Texture* texture = SDL_CreateTextureFromSurface(Game::renderer, tmpSurface);
    SDL_FreeSurface(tmpSurface);

    return texture;
}

void TextureManager::drawSprite(SDL_Texture* texture, SDL_Rect src, SDL_Rect dst)
{
    SDL_RenderCopy(Game::renderer, texture, &src, &dst);
}

