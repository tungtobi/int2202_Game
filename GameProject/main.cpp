#include "Game.h"
#include "Sprite.h"
#include "Player.h"
#include "Fruit.h"

const int SCREEN_WIDTH = 800;
const int SCREEN_HEIGHT = 600;
const char* TITLE = "INT2202 4";
const bool FULLSCREEN = false;
const int FPS = 60;

int main(int argc, char* argv[])
{
    Game* director = new Game();

    const int frameDelay = int(1000 / FPS);

    director->init(TITLE, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, SCREEN_WIDTH, SCREEN_HEIGHT, FULLSCREEN);


    Player* player = new Player();

    Fruit* fruit = new Fruit();

    while (director->isRunning())
    {
        director->update();
        player->update();
    }

    director->clean();
    return 0;
}
