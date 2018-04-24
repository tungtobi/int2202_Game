#include "Game.h"
#include "Sprite.h"
#include "Player.h"

Game* DIRECTOR = nullptr;

const int SCREEN_WIDTH = 800;
const int SCREEN_HEIGHT = 600;

const char* TITLE = "INT2202 4";

const bool FULLSCREEN = false;

const int FPS = 60;

int main(int argc, char* argv[])
{
    DIRECTOR = new Game();

    const int frameDelay = int(1000 / FPS);

    int frameStart;
    int frameTime;

    DIRECTOR->init(TITLE, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, SCREEN_WIDTH, SCREEN_HEIGHT, FULLSCREEN);

    Player* player = new Player();

    while (DIRECTOR->isRunning())
    {
        //DIRECTOR->listenEvents();
        DIRECTOR->update();
        player->update();

        if (frameDelay > frameTime)
        {
            SDL_Delay(frameDelay - frameTime);
        }
    }


    DIRECTOR->clean();
    return 0;
}
