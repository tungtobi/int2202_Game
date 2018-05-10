#ifndef ANIMATION_H_
#define ANIMATION_H_

#include "Sprite.h"

class Animation
{
public:
    void loadImage(const char* _fileName);
    ~Animation();

    Sprite sprite;

    void runAnimation();
    void initNormalSprite();

    int frameNumber = 3;
    std::string fileName;
    int keyFrame = 0;

private:
    int speed = 10;
    int dt = 0;
};

#endif // ANIMATION_H_
