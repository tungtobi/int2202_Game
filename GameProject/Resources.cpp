#include "Resources.h"
#include <iostream>

Resources::Resources(int type)
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
    std::cout << "Delete s" << std::endl;
    delete hurted;
    std::cout << "Delete st" << std::endl;
}
