#include "Animation.h"
#include "TextManager.h"

void Animation::loadImage(const char* _fileName)
{
    fileName = _fileName;
    keyFrame = 0;

    initNormalSprite();
}

void Animation::initNormalSprite()
{
    sprite.loadFrame((fileName + "_0.png").c_str());
}

void Animation::runAnimation()
{
    dt++;

    if (FPS / dt == speed)
    {
        dt = 0;
        keyFrame = (keyFrame + 1) % frameNumber + 1;
        std::string path = fileName + '_' + convertIntToStr(keyFrame) + ".png";
        sprite.loadFrame(path.c_str());
    }
}

Animation::~Animation()
{
    SDL_DestroyTexture(sprite.texture);
    std::cout << "Delete Animate" << std::endl;
}
