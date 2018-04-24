#include "Game.h"
#include "Sprite.h"
#include "Player.h"
#include "Fruit.h"
#include "Layer.h"

const int SCREEN_WIDTH = 800;
const int SCREEN_HEIGHT = 600;
const char* TITLE = "INT2202 4";
const bool FULLSCREEN = false;
const int FPS = 60;


int main(int argc, char* argv[])
{
    Game* director = new Game();

    const int frameDelay = 1000 / FPS;
    Uint32 frameStart;
    int frameTime;

    director->init(TITLE, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, SCREEN_WIDTH, SCREEN_HEIGHT, FULLSCREEN);

    Layer* layer = new Layer();


    while (director->isRunning())
    {
        frameStart = SDL_GetTicks();

        director->update();
        layer->update();

        frameTime = SDL_GetTicks() - frameStart;

        if (frameDelay > frameTime)
        {
            SDL_Delay(frameDelay - frameTime);
        }
    }

    director->clean();
    return 0;
}
