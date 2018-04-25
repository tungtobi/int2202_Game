#include "Game.h"
#include "Sprite.h"
#include "Player.h"
#include "Fruit.h"
#include "Layer.h"
#include "Director.h"

Layer* layer;

int main(int argc, char* argv[])
{
    Game* game = new Game();
    Director director;

    const int frameDelay = 1000 / FPS;
    Uint32 frameStart;
    int frameTime;

    layer = new Layer();

    while (game->isRunning())
    {
        frameStart = SDL_GetTicks();

        game->update();
        director.update();
        layer->update();

        frameTime = SDL_GetTicks() - frameStart;

        if (frameDelay > frameTime)
        {
            SDL_Delay(frameDelay - frameTime);
        }
    }

    game->clean();
    return 0;
}
