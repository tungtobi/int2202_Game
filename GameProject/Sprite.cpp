#include "Sprite.h"

Sprite::Sprite(const char* fileName)
{
    texture = TextureManager::LoadTexture(fileName);
}

void Sprite::attr(const int _w, const int _h, const float scale, const float angle)
{
    srcRect.w = _w;
    srcRect.h = _h;
    srcRect.x = 0;
    srcRect.y = 0;

    dstRect.w = _w * scale;
    dstRect.h = _h * scale;
}

void Sprite::update()
{


}
void Sprite::render()
{
    SDL_RenderCopy(Game::renderer, texture, &srcRect, &dstRect);
}

Sprite::~Sprite()
{

}
