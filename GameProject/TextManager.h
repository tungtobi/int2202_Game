#ifndef TEXTMANAGER_H_
#define TEXTMANAGER_H_

#define LEFT_ALIGN 0
#define CENTER_ALIGN 1
#define RIGHT_ALIGN 2

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
    SDL_Color color = {255, 255, 255};

    SDL_Texture* texture;

    void render(const int _x, const int _y, const int align);
    void initTexture();

private:
    SDL_Rect dstRect;
};

std::string convertIntToStr(unsigned int number);

#endif // TEXTMANAGER_H_
