#include "NotificationLayer.h"
#include <cmath>

extern Game* game;

NotificationLayer::NotificationLayer(const int _score, const int _score2, const bool _isMultyPlayer)
{
    score = _score;
    score2 = _score2;
    isMultyPlayer = _isMultyPlayer;
    loadBestScore();

    background.setPosition(SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2);
    initTextLabel();
}

void NotificationLayer::loadBestScore()
{
    bestScore = std::max(bestScore, std::max(score, score2));
}

void NotificationLayer::initTextLabel()
{
    if (isMultyPlayer)
    {
        if (score > score2)
        {
            line1.para = "Black pig win!";
            scoreLabel.para = convertIntToStr(score);
        }
        else
        {
            line1.para = "Pink pig win!";
            scoreLabel.para = convertIntToStr(score2);
        }
    }
    else
    {
        line1.para = "Your score";
        scoreLabel.para = convertIntToStr(score);
    }

    line1.initTexture();
    scoreLabel.initTexture();

    line2.para = "Your best";
    line2.initTexture();

    line3.para = "Press 'Space' to continue!";
    line3.initTexture();

    bestScoreLabel.para = convertIntToStr(bestScore);
    bestScoreLabel.initTexture();
}

void NotificationLayer::render()
{
    SDL_RenderClear(Game::renderer);

    background.render();

    line1.render(SCREEN_WIDTH / 2 - 120, SCREEN_HEIGHT / 2 + 100, CENTER_ALIGN);
    scoreLabel.render(SCREEN_WIDTH / 2 - 120, SCREEN_HEIGHT / 2 + 160, CENTER_ALIGN);

    line2.render(SCREEN_WIDTH / 2 + 120, SCREEN_HEIGHT / 2 + 100, CENTER_ALIGN);
    bestScoreLabel.render(SCREEN_WIDTH / 2 + 120, SCREEN_HEIGHT / 2 + 160, CENTER_ALIGN);

    line3.render(SCREEN_WIDTH / 2, SCREEN_HEIGHT - 20, CENTER_ALIGN);

    SDL_RenderPresent(Game::renderer);
}

void NotificationLayer::listenEvent()
{
    if (Game::event.type == SDL_KEYDOWN)
    {
        if (Game::event.key.keysym.sym == SDLK_SPACE)
            //if (game->scene != PLAY_MODE_1)
        {
            game->play(PLAY_MODE_1);
        }
    }
}

void NotificationLayer::update()
{
    listenEvent();
    render();
}
