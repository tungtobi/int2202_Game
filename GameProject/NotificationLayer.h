#ifndef NOTIFICATIONLAYER_H_
#define NOTIFICATIONLAYER_H_

#include "Game.h"
#include "TextManager.h"
#include "Sprite.h"
#include <vector>

class NotificationLayer
{
public:
    NotificationLayer(const int _score);
    void update();

private:
    int score, bestScore = 0;
    double dt = 0;
    Text line1{LIGHT, 16},
    line2{LIGHT, 16},
    scoreLabel{BOLD, 120},
    bestScoreLabel{BOLD, 120};
    Sprite background{"res/backgroundNotice.png"};

    void initTextLabel();
    void render();
    void listenEvent();
    void loadBestScore();
    void runSplashScene();
};

#endif // NOTIFICATIONLAYER_H_
