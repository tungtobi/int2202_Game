#ifndef GAME_H_
#define GAME_H_

#include "Sprite.h"
#include <iostream>
#include <vector>
#include <SDL2/SDL.h>
#include <SDL_image.h>
#include "TextureManager.h"
#include "Fruit.h"

class Game
{
public:
    Game();
    ~Game();

    void init(const char* title, int x, int y, const int width, const int height, const bool fullscreen);

    void listenEvents();
    void update();
    void render();
    //void renderSprite(Sprite* sprite);
    void clean();

    bool isRunning()
    {
        return _isRunning;
    }

    static SDL_Renderer* renderer;
    static SDL_Event event;

private:
    int dt = 0;
    bool _isRunning;
    SDL_Window* window;
};

#endif // GAME_H_
