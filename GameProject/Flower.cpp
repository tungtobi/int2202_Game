#include "Flower.h"
#include "Layer.h"

extern Layer* layer;

Flower::Flower()
{
    animate.frameNumber = 9;
    animate.loadImage("res/flower/");
    animate.sprite.setPosition(SCREEN_WIDTH / 2, 300);
    std::cout << "Flower" << std::endl;
}

void Flower::render()
{
    animate.sprite.render();
}

void Flower::update()
{
    if (animate.keyFrame >= animate.frameNumber)
    {
        layer->removeFlower(this);
    }
    else
    {
        animate.runAnimation();
    }

    checkCaught(layer->player);
    checkCaught(layer->player2);
}

void Flower::checkCaught(Player& player)
{
    if (2 * abs(player.x - animate.sprite.dstRect.x) < animate.sprite.dstRect.w + player.w && !player.isStuck())
    {
        player.score /= 2;
        player.getStuck();
        layer->updateScore(player);
    }
}
