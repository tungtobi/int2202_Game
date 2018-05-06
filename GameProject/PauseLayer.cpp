#include "PauseLayer.h"

PauseLayer::PauseLayer()
{
    pauseLabel.para = "PAUSE";
    pauseLabel.initTexture();
}

void PauseLayer::render()
{
    pauseLabel.render(SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2, CENTER_ALIGN);
    SDL_RenderPresent(Game::renderer);
}

PauseLayer::~PauseLayer()
{

}
