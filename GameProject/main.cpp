#include "Game.h"
#include "Sprite.h"
#include "Player.h"
#include "Fruit.h"
#include "Layer.h"

Game* game;

int main(int argc, char* argv[])
{
    game = new Game();

    game->update();

    game->clean();
    return 0;
}
