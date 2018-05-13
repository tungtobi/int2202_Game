#include "Game.h"

Game* game;

int main(int argc, char* argv[])
{
    game = new Game();

    game->update();

    game->clean();
    return 0;
}
