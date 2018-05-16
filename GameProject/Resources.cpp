#include "Resources.h"
#include <iostream>

void Resources::setType(int type)
{
    switch (type)
    {
    case BLACK_PIG:
        normal = "res/blackPig";
        hurted = "res/blackPigHurted.png";
        break;
    case PINK_PIG:
        normal = "res/pinkPig";
        hurted = "res/pinkPigHurted.png";
        break;
    }
}

Resources::~Resources()
{
    delete normal;
    delete hurted;
}
