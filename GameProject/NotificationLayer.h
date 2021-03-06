#ifndef NOTIFICATIONLAYER_H_
#define NOTIFICATIONLAYER_H_

#include "Game.h"
#include "TextManager.h"
#include "Sprite.h"
#include <vector>

class NotificationLayer
{
public:
    NotificationLayer(const int _score, const int _score2, const bool _isMultyPlayer);
    void update();

private:
    int score, score2;
    Text line1{LIGHT, 16},
    line2{LIGHT, 16},
    line3{LIGHT, 12},
    scoreLabel{BOLD, 120},
    bestScoreLabel{BOLD, 120};
    Sprite background{"res/backgroundNotice.png"};
    bool isMultyPlayer;
    void initTextLabel();
    void render();
    void listenEvent();
    void loadBestScore();
};

#endif // NOTIFICATIONLAYER_H_
