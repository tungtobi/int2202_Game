#ifndef GAME_H_
#define GAME_H_

#define SCREEN_WIDTH 800
#define SCREEN_HEIGHT 600
#define TITLE "Hungry Pig"
#define FULLSCREEN false
#define FPS 60

enum SceneType
{
    MENU = 0,
    PLAY_MODE_1,
    PLAY_MODE_2,
    SHOW_SCORE
};

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
    void showScoreNotice(const int _score, const int _score2, const bool _isMultyPlayer);
    void play(SceneType mode);

    SceneType scene = PLAY_MODE_2;

private:
    int dt = 0;
    bool isRunning;
    SDL_Window* window;

    void listenEvents();
    void init(const char* title, int x, int y, const int width, const int height, const bool fullscreen);
};

#endif // GAME_H_
