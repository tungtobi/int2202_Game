#include "Game.h"
#include "Sprite.h"

Game* DIRECTOR = nullptr;

const int SCREEN_WIDTH = 800;
const int SCREEN_HEIGHT = 600;

const char* TITLE = "INT2202 4";

const bool FULLSCREEN = false;

int main(int argc, char* argv[])
{
    DIRECTOR = new Game();

    DIRECTOR->init(TITLE, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, SCREEN_WIDTH, SCREEN_HEIGHT, FULLSCREEN);

    Sprite spr = DIRECTOR->addSprite("res/spaceShips_008.png");


    while (DIRECTOR->isRunning())
    {
        DIRECTOR->listenEvents();
        DIRECTOR->update();
        DIRECTOR->render(spr);
    }

    DIRECTOR->clean();
    return 0;
}
