#include "PauseLayer.h"

PauseLayer::PauseLayer()
{
    background.setPosition(SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2);
    pauseLabel.para = "Pause! Press 'P' to continue.";
    pauseLabel.initTexture();
}

void PauseLayer::render()
{
    background.render();
    pauseLabel.render(SCREEN_WIDTH - 8, SCREEN_HEIGHT - 12, RIGHT_ALIGN);
    SDL_RenderPresent(Game::renderer);
}

PauseLayer::~PauseLayer()
{

}
