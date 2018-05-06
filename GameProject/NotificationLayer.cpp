#include "NotificationLayer.h"

extern Game* game;

NotificationLayer::NotificationLayer(const int _score)
{
    score = _score;
    loadBestScore();


    background.setPosition(SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2);
    initTextLabel();
}

void NotificationLayer::loadBestScore()
{
    if (score > bestScore)
    {
        bestScore = score;
    }
}

void NotificationLayer::initTextLabel()
{
    line1.para = "Your score";
    line1.initTexture();

    scoreLabel.para = convertIntToStr(score);
    scoreLabel.initTexture();

    line2.para = "Your best";
    line2.initTexture();

    bestScoreLabel.para = convertIntToStr(bestScore);
    bestScoreLabel.initTexture();
}

void NotificationLayer::render()
{
    SDL_RenderClear(Game::renderer);

    if (dt >= 0.3)
    {
        background.render();

        line1.render(SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2 - 200, CENTER_ALIGN);
        scoreLabel.render(SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2 - 136, CENTER_ALIGN);

        line2.render(SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2 - 64, CENTER_ALIGN);
        bestScoreLabel.render(SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2, CENTER_ALIGN);
    }
    else
    {
        dt += 0.15;
    }


    SDL_RenderPresent(Game::renderer);
}

void NotificationLayer::listenEvent()
{
    if (Game::event.type == SDL_KEYDOWN)
    {
        switch (Game::event.key.keysym.sym)
        {
        case SDLK_SPACE:
            if (game->gameState != PLAY_MODE_1)
            {
                game->playSinglyMode();
            }
            break;
        }
    }
}

void NotificationLayer::update()
{
    listenEvent();

    render();
}
