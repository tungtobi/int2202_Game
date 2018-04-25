#include "Sprite.h"

Sprite::Sprite(const char* fileName)
{
    texture = TextureManager::LoadTexture(fileName);
    SDL_QueryTexture(texture, NULL, NULL, &srcRect.w, &srcRect.h);
    attr(1, 0);
    anchorPoint = {dstRect.w / 2, dstRect.h / 2};
}

void Sprite::attr(const float scale, const float angle)
{
    srcRect.x = 0;
    srcRect.y = 0;

    dstRect.w = srcRect.w * scale;
    dstRect.h = srcRect.h * scale;
}

void Sprite::update()
{

}

void Sprite::render()
{
    SDL_RenderCopyEx
    (
        Game::renderer,
        texture,
        &srcRect,
        &dstRect,
        angle,
        &anchorPoint,
        SDL_FLIP_NONE
    );
}

Sprite::~Sprite()
{
    delete texture;
}
