#include "Menu.h"
#include "Game.h"
#include "Mixer.h"

using namespace std;

extern Game* game;

string menuText[size] =
{
    "1-Player Mode",
    "2-Players Mode",
    "Audio: ON",
    "Quit game"
};

Menu::Menu()
{
    // ve ra hinh nen
    background.setPosition(SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2);
    initLabels();
    cout << "init labels" << endl;
    select(QUIT, SINGLY_PLAY);
}

void Menu::initLabels()
{
    for (int i = 0; i < size; i++)
    {
        menuLabel[i].para = menuText[i];
        menuLabel[i].initTexture();
    }

    //tieu de game
    gameInfo.para = "Hungry Piggy v1.0.1";
    gameInfo.initTexture();
}

void Menu::updateSoundLabel(bool _isMuted)
{
    string title = "Audio: ",
           status = _isMuted ? "OFF" : "ON";
    menuText[SOUND] = title + status;
    select(QUIT, SOUND);
}

// lua chon doi mau, lua chon truoc chuyen thanh trang
void Menu::select(MenuItem prevSelect, MenuItem selected)
{
    menuLabel[prevSelect].para = menuText[prevSelect];
    menuLabel[prevSelect].color = {255, 255, 255};
    menuLabel[prevSelect].initTexture();

    menuLabel[selected].para = menuText[selected] + " \n";
    menuLabel[selected].color = {0, 0, 127};
    menuLabel[selected].initTexture();

    selection = selected;
}

void Menu::enterSelection()
{
    switch (selection)
    {
    case SINGLY_PLAY:
    case MULTY_PLAY:
        game->play(SceneType(selection + 1));
        break;
    case SOUND:
        game->mixManager.muted();
        updateSoundLabel(game->mixManager.isMuted);
        break;
    case QUIT:
        game->clean();
        break;
    default:
        break;
    }
}

void Menu::listenEvents()
{
    if (Game::event.type == SDL_KEYDOWN)
    {
        MenuItem newSelect;
        switch (Game::event.key.keysym.sym)
        {
        case SDLK_DOWN:
            game->mixManager.playSoundEffect(EATING_SOUND);
            newSelect = MenuItem((selection + 1) % size);
            select(selection, newSelect);
            break;
        case SDLK_UP:
            game->mixManager.playSoundEffect(EATING_SOUND);
            newSelect = MenuItem((selection + size - 1) % size);
            select(selection, newSelect);
            break;
        case SDLK_SPACE:
            game->mixManager.playSoundEffect(EATING_SOUND);
            enterSelection();
            break;
        }
        SDL_Delay(300);
        SDL_FlushEvent(SDL_KEYDOWN);
    }
}

void Menu::render()
{
    SDL_RenderClear(Game::renderer);

    background.render();
    for (int i = 0; i < size; i++)
    {
        menuLabel[i].render(SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2 + 30 * i + 90, CENTER_ALIGN);
    }
    gameInfo.render(SCREEN_WIDTH - 8, SCREEN_HEIGHT - 12, RIGHT_ALIGN);

    SDL_RenderPresent(Game::renderer);
}

void Menu::update()
{
    listenEvents();
    render();
}
