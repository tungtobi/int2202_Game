#include "Sprite.h"

void Sprite::getContentSize(const int _w, const int _h, const float scale)
{
    dstRect->h = _h * scale;
    dstRect->w = _w * scale;
}
