#ifndef GAME_H_
#define GAME_H_

#define SCREEN_WIDTH 800
#define SCREEN_HEIGHT 600
#define TITLE "Hungry Pig"
#define FULLSCREEN false
#define FPS 60
#define PLAY_MODE_1 1
#define PLAY_MODE_2 2
#define MENU 0
#define SHOW_SCORE 3

#include <iostream>
#include <SDL2/SDL.h>
#include <SDL_image.h>

class Game
{
public:
    Game();
    ~Game();

    void update();
    void clean();

    static SDL_Renderer* renderer;
    static SDL_Event event;
    //static bool isPause;
    void showScoreNotice(const int _score);
    void playSinglyMode();

    int gameState = PLAY_MODE_1;

private:
    int dt = 0;
    bool isRunning;
    SDL_Window* window;

    void listenEvents();
    void init(const char* title, int x, int y, const int width, const int height, const bool fullscreen);
};

#endif // GAME_H_
