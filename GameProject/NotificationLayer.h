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
    int score, bestScore = 0, score2;
    Text line1{LIGHT, 16},
    line2{LIGHT, 16},
    line3{LIGHT, 16},
    scoreLabel{BOLD, 100},
    bestScoreLabel{BOLD, 100};
    Sprite background{"res/backgroundNotice.png"};
    bool isMultyPlayer;
    void initTextLabel();
    void render();
    void listenEvent();
    void loadBestScore();
};

#endif // NOTIFICATIONLAYER_H_
