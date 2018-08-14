#include "NotificationLayer.h"
#include <cmath>

extern Game* game;

NotificationLayer::NotificationLayer(const int _score, const int _score2, const bool _isMultyPlayer)
{
    Game::mixManager.playSoundEffect(GAMEOVER_SOUND);

    score = _score;
    score2 = _score2;
    isMultyPlayer = _isMultyPlayer;
    loadBestScore();

    background.setPosition(SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2);
    initTextLabel();
}

void NotificationLayer::loadBestScore()
{
    game->bestScore = std::max(game->bestScore, std::max(score, score2));
}

void NotificationLayer::initTextLabel()
{
    if (isMultyPlayer)
    {
        if (score > score2)
        {
            line1.para = "PLAYER 1 win!";
            scoreLabel.para = convertIntToStr(score);
        }
        else
        {
            line1.para = "PLAYER 2 win!";
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

    line3.para = "Menu \n";
    line3.initTexture();

    bestScoreLabel.para = convertIntToStr(game->bestScore);
    bestScoreLabel.initTexture();
}

void NotificationLayer::render()
{
    SDL_RenderClear(Game::renderer);

    background.render();

    line1.render(SCREEN_WIDTH / 2 - 120, SCREEN_HEIGHT / 2 + 70, CENTER_ALIGN);
    scoreLabel.render(SCREEN_WIDTH / 2 - 120, SCREEN_HEIGHT / 2 + 140, CENTER_ALIGN);

    line2.render(SCREEN_WIDTH / 2 + 120, SCREEN_HEIGHT / 2 + 70, CENTER_ALIGN);
    bestScoreLabel.render(SCREEN_WIDTH / 2 + 120, SCREEN_HEIGHT / 2 + 140, CENTER_ALIGN);

    line3.render(SCREEN_WIDTH - 8, SCREEN_HEIGHT - 12, RIGHT_ALIGN);

    SDL_RenderPresent(Game::renderer);
}

void NotificationLayer::listenEvent()
{
    if (Game::event.type == SDL_KEYDOWN)
    {
        if (Game::event.key.keysym.sym == SDLK_SPACE)
        {
            game->mixManager.playSoundEffect(EATING_SOUND);
            game->showMenu();
        }
    }
}

void NotificationLayer::update()
{
    listenEvent();
    render();
}
