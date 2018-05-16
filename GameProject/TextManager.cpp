#include "TextManager.h"

Text::Text(const char* path, const int _size)
{
    size = _size;
    font = TTF_OpenFont(path, size);
    std::cout << "Text created!" << std::endl;

    initTexture();

}

void Text::initTexture()
{
    SDL_Surface* textSurface = TTF_RenderText_Solid(font, para.c_str(), color);
    texture = SDL_CreateTextureFromSurface(Game::renderer, textSurface);
    SDL_FreeSurface(textSurface);
    delete textSurface;

    SDL_QueryTexture(texture, NULL, NULL, &dstRect.w, &dstRect.h);
}

void Text::render(const int _x, const int _y, Align align)
{
    switch (align)
    {
    case CENTER_ALIGN:
        dstRect.x = _x - dstRect.w / 2;
        break;
    case LEFT_ALIGN:
        dstRect.x = _x;
        break;
    case RIGHT_ALIGN:
        dstRect.x = _x - dstRect.w;
        break;
    }

    dstRect.y = _y - dstRect.h / 2;

    SDL_RenderCopy(Game::renderer, texture, NULL, &dstRect);
}

Text::~Text()
{
    delete font;
    SDL_DestroyTexture(texture);
    delete texture;
}

std::string convertIntToStr(unsigned int number)
{
    std::string str = "";

    if (number == 0)
    {
        str = "0";
    }

    while (number > 0)
    {
        str = char(number % 10 + '0') + str;
        number /= 10;
    }

    return str;
}
