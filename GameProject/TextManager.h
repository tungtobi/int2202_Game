#ifndef TEXTMANAGER_H_
#define TEXTMANAGER_H_

#include "Game.h"
#include <SDL2/SDL_ttf.h>

class Text
{
public:
    Text(const char* path, const int _size);
    ~Text();

    std::string para;
    int size;

    TTF_Font* font;
    SDL_Color color;

    SDL_Texture* texture;

    void render(const int _x, const int _y);
    void initTexture();

private:
    SDL_Rect dstRect;
};

std::string convertIntToStr(unsigned int number);

#endif // TEXTMANAGER_H_
