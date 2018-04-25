#ifndef GAME_H_
#define GAME_H_

#define SCREEN_WIDTH 800
#define SCREEN_HEIGHT 600
#define TITLE "INT2202 4"
#define FULLSCREEN false
#define FPS 60

#include "Sprite.h"
#include <iostream>
#include <vector>
#include <SDL2/SDL.h>
#include <SDL_image.h>
#include "TextureManager.h"

class Game
{
public:
    Game();
    ~Game();

    void update();
    void clean();

    static SDL_Renderer* renderer;
    static SDL_Event event;

private:
    int dt = 0;

    bool isRunning;

    SDL_Window* window;

    void listenEvents();
    void init(const char* title, int x, int y, const int width, const int height, const bool fullscreen);
};

#endif // GAME_H_
