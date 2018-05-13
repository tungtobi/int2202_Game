#ifndef MENU_H_
#define MENU_H_

#include <vector>
#include "TextManager.h"
#include "Sprite.h"

enum MenuItem
{
    SINGLY_PLAY = 0,
    MULTY_PLAY,
    SOUND,
    QUIT
};

const int size = 4;

class Menu
{
private:
    std::vector<Text> menuLabel{size};
    Text gameInfo{LIGHT, 12};
    MenuItem selection = SINGLY_PLAY;
    Sprite background{"res/backgroundNotice.png"};
    void initLabels();
    void listenEvents();
    void select(MenuItem prevSelect, MenuItem selected);
    void enterSelection();
    void updateSoundLabel(bool _isMuted);
    void render();
public:
    Menu();
    void update();
};

#endif // MENU_H_
