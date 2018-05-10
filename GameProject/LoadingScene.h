#ifndef LOADINGSCENE_H_
#define LOADINGSCENE_H_

#include "Game.h"
#include "Sprite.h"
#include "TextManager.h"

void runSplashScene(const Uint32 time)
{
    Sprite background{"res/loadingScene.png"};
    background.setPosition(SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2);
    Text text{LIGHT, 12};
    text.para = "Loading...";
    text.initTexture();

    SDL_RenderClear(Game::renderer);
    background.render();
    text.render(SCREEN_WIDTH - 8, SCREEN_HEIGHT - 12, RIGHT_ALIGN);
    SDL_RenderPresent(Game::renderer);
    SDL_Delay(time);
}

#endif // LOADINGSCENE_H_
