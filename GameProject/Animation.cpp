#include "Animation.h"
#include "TextManager.h"

Animation::Animation(const char* _fileName)
{
    fileName = _fileName;
    keyFrame = 0;

    sprite = new Sprite((fileName + "_0.png").c_str());
}

void Animation::initNormalSprite()
{
    sprite->loadFrame((fileName + "_0.png").c_str());
}

void Animation::runAnimation()
{
    dt++;

    if (FPS / dt == speed)
    {
        dt = 0;
        keyFrame = (keyFrame + 1) % frameNumber + 1;
        std::string path = fileName + '_' + convertIntToStr(keyFrame) + ".png";
        sprite->loadFrame(path.c_str());
    }
}
