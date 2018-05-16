#ifndef TEXTMANAGER_H_
#define TEXTMANAGER_H_

#define BOLD "res/font/Maplestory Bold.ttf"
#define LIGHT "res/font/Maplestory Light.ttf"

#include "Game.h"
#include <SDL2/SDL_ttf.h>

enum Align
{
    LEFT_ALIGN = 0,
    CENTER_ALIGN,
    RIGHT_ALIGN
};

class Text
{
public:
    Text(const char* path = BOLD, const int _size = 18);
    ~Text();

    std::string para;
    int size;

    TTF_Font* font;
    SDL_Color color = {255, 255, 255};

    SDL_Texture* texture;

    void render(const int _x, const int _y, Align align);
    void initTexture();

private:
    SDL_Rect dstRect;
};

std::string convertIntToStr(unsigned int number);

#endif // TEXTMANAGER_H_
