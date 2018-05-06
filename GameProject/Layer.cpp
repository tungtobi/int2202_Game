#include "Layer.h"
#include <algorithm>
#include <cstdlib>
#include "PauseLayer.h"

extern Game* game;

Layer::Layer()
{
    background.setPosition(SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2);
    updateScore();
}

void Layer::addFruit(Fruit* f)
{
    fruits.push_back(f);
}

void Layer::removeFruit(Fruit* f)
{
    fruits.erase(std::remove(fruits.begin(), fruits.end(), f));
    delete f;
}

void Layer::renderSprite()
{
    player.render();

    for (Fruit* f : fruits)
    {
        if (f)
        {
            f->sprite->render();
        }
    }
}

void Layer::update()
{
    director.update();
    player.update();

    if (!isPause)
    {
        for (Fruit* f : fruits)
        {
            if (f)
            {
                f->update();
                f->checkCaught(player);
            }
        }

        updateTime();
        render();
    }
    else
    {
        static PauseLayer pauseLayer;
        pauseLayer.render();
    }

}

void Layer::updateScore()
{
    scoreLabel.para = convertIntToStr(score);
    scoreLabel.initTexture();
}

void Layer::updateTime()
{
    time -= 0.015;
    timeLabel.para = convertIntToStr(time) + 's';
    if (time < 11)
    {
        timeLabel.color = {255, 0, 0};
        if (time <= 0 && game->gameState == PLAY_MODE_1)
        {
            game->showScoreNotice(score);
        }
    }
    else
    {
        timeLabel.color = {255, 255, 255};
    }

    timeLabel.initTexture();
}

void Layer::render()
{
    SDL_RenderClear(Game::renderer);

    background.render();

    renderSprite();

    scoreLabel.render(60, 40, LEFT_ALIGN);
    timeLabel.render(SCREEN_WIDTH / 2, 40, CENTER_ALIGN);

    SDL_RenderPresent(Game::renderer);
}

Layer::~Layer()
{
    /*while (fruits.size() > 0)
    {
        removeFruit(fruits[0]);
    }*/
    fruits.clear();
}
