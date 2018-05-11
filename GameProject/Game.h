#ifndef GAME_H_
#define GAME_H_

#define SCREEN_WIDTH 800
#define SCREEN_HEIGHT 600
#define TITLE "Hungry Piggy Game"
#define FULLSCREEN false
#define FPS 60

#include <iostream>
#include <SDL2/SDL.h>
#include <SDL_image.h>
#include "Mixer.h"

enum SceneType
{
    MENU = 0,
    PLAY_MODE_1,
    PLAY_MODE_2,
    SHOW_SCORE
};

class Game
{
public:
    Game();

    int bestScore;
    SceneType scene;
    static SDL_Renderer* renderer;
    static SDL_Event event;
    static MixManager mixManager;

    void update();
    void showMenu();
    void play(SceneType mode);
    void showScoreNotice
    (
        const int _score,
        const int _score2,
        const bool _isMultyPlayer
    );
    void clean();

    ~Game();

private:
    int dt = 0;
    bool isRunning;
    SDL_Window* window;
    void listenEvents();
    void initSDL
    (
        const char* title,
        const int x,
        const int y,
        const int width,
        const int height,
        const bool fullscreen
    );
};

#endif // GAME_H_
