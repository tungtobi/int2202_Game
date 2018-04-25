#include "Game.h"
#include "Sprite.h"
#include "Player.h"
#include "Fruit.h"
#include "Layer.h"

int main(int argc, char* argv[])
{
    Game* game = new Game();

    game->update();

    game->clean();
    return 0;
}
