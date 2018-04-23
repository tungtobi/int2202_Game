#ifndef GAME_H_
#define GAME_H_

#include <iostream>
#include <SDL2/SDL.h>

class Game
{
public:
    Game();
    ~Game();

    void init(const char* title, int x, int y, const int width, const int height, const bool fullscreen);

    void listenEvents();
    void update();
    void render();
    void clean();

    bool isRunning()
    {
        return _isRunning;
    }

private:
    int cnt = 0;
    bool _isRunning;
    SDL_Window* window;
    SDL_Renderer* renderer;
};

#endif // GAME_H_
