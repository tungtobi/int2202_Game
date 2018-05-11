#include "Layer.h"
#include <algorithm>
#include <cstdlib>
#include "PauseLayer.h"
#include "Game.h"

extern Game* game;

Layer::Layer(const bool _isMultyPlayer)
{
    background.setPosition(SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2);
    isMultyPlayer = _isMultyPlayer;
    if (!isMultyPlayer)
    {
        player2.y = 2 * SCREEN_HEIGHT;
        player.x = SCREEN_WIDTH / 2;
        updateScore(player);
        updateScore(player2);
    }
    else
    {
        background.loadFrame("res/backgroundMulty.png");
        player2.x = SCREEN_WIDTH / 3;
        player.x = 2 * SCREEN_WIDTH / 3;
        updateScore(player);
        updateScore(player2);
    }
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

void Layer::addFlower(const int type)
{
    Flower* tmp = new Flower();
    switch (type)
    {
    case BLACK_PIG:
        tmp->animate.sprite.setPosition(player2.x, player2.y);
        break;
    case PINK_PIG:
        tmp->animate.sprite.setPosition(player.x, player.y);
        break;
    }
    flowers.push_back(tmp);
}

void Layer::removeFlower(Flower* f)
{
    flowers.erase(std::remove(flowers.begin(), flowers.end(), f));
    delete f;
}

void Layer::renderSprite()
{
    player.render();
    if (isMultyPlayer)
    {
        player2.render();
    }

    for (Fruit* f : fruits)
    {
        if (f)
        {
            f->sprite.render();
        }
    }

    for (Flower* f : flowers)
    {
        if (f)
        {
            f->render();
        }
    }
}

void Layer::update()
{
    director.update();
    player.update();
    if (isMultyPlayer)
    {
        player2.update();
    }
    if (!isPause)
    {
        updateFruit();
        updateTime();

        render();
    }
    else
    {
        static PauseLayer pauseLayer;
        pauseLayer.render();
    }

}

void Layer::updateFruit()
{
    for (Fruit* f : fruits)
    {
        if (f)
        {
            f->update();
        }
    }

    for (Flower* f : flowers)
    {
        if (f)
        {
            f->update();
        }
    }
}

void Layer::updateScore(const Player& _player)
{
    if (_player.id == BLACK_PIG)
    {
        scoreLabel.para = convertIntToStr(_player.score);
        scoreLabel.initTexture();
    }
    else
    {
        score2Label.para = convertIntToStr(_player.score);
        score2Label.initTexture();
    }
}

void Layer::updateTime()
{
    time -= 0.015;
    static bool isWarning;
    timeLabel.para = convertIntToStr(time) + 's';
    if (time < 11)
    {
        if (!isWarning)
        {
            Game::mixManager.playSoundEffect(WARNING_SOUND);
            isWarning = true;
        }
        timeLabel.color = {255, 0, 0};
        if (time <= 0)
        {
            game->showScoreNotice(player.score, player2.score, isMultyPlayer);
        }
    }
    else
    {
        isWarning = false;
        timeLabel.color = {255, 255, 255};
    }

    timeLabel.initTexture();
}

void Layer::renderLabel()
{
    scoreLabel.render(60, 40, LEFT_ALIGN);
    if (isMultyPlayer)
    {
        score2Label.render(SCREEN_WIDTH - 60, 40, RIGHT_ALIGN);
    }
    timeLabel.render(SCREEN_WIDTH / 2, 40, CENTER_ALIGN);
}

void Layer::render()
{
    SDL_RenderClear(Game::renderer);

    background.render();

    renderSprite();

    renderLabel();

    SDL_RenderPresent(Game::renderer);
}

Layer::~Layer()
{
    fruits.clear();
}
