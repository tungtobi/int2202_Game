#include "Game.h"
#include "Player.h"
#include "Sprite.h"
#include "Fruit.h"
#include <SDL2/SDL_ttf.h>
#include "Layer.h"
#include "NotificationLayer.h"

SDL_Renderer* Game::renderer = nullptr;
SDL_Event Game::event;
const int frameDelay = 1000 / FPS;
Layer* layer;
NotificationLayer* notifiLayer;

Game::Game()
{
    init(TITLE, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, SCREEN_WIDTH, SCREEN_HEIGHT, FULLSCREEN);
    layer = new Layer();
    //notifiLayer = new NotificationLayer(10);
}

Game::~Game()
{

}

void Game::init(const char* title, int x, int y, const int width, const int height, const bool fullscreen)
{
    int flags = 0;
    if (fullscreen)
    {
        flags = SDL_WINDOW_FULLSCREEN;
    }

    if (SDL_Init(SDL_INIT_EVERYTHING) == 0)
    {
        std::cout << "Subsystem Initialised!..." << std::endl;

        window = SDL_CreateWindow(title, x, y, width, height, flags);
        if (window)
        {
            std::cout << "Window created!" << std::endl;
        }

        renderer = SDL_CreateRenderer(window, -1, 0);
        if (renderer)
        {
            SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
            std::cout << "Renderer created!" << std::endl;
        }

        isRunning = true;
    }
    else
    {
        isRunning = false;
    }

    TTF_Init();

    if (TTF_Init() < 0)
    {
        std::cout << "TTF Error!" << std::endl;
    }
}

void Game::update()
{
    while (isRunning)
    {
        Uint32 frameStart = SDL_GetTicks();

        listenEvents();

        switch (gameState)
        {
        case PLAY_MODE_1:
            layer->update();
            break;
        case SHOW_SCORE:
            if (notifiLayer)
                notifiLayer->update();
            break;
        }

        int frameTime = SDL_GetTicks() - frameStart;

        if (frameDelay > frameTime)
        {
            SDL_Delay(frameDelay - frameTime);
        }
    }
}

void Game::listenEvents()
{
    SDL_PollEvent(&event);

    switch (event.type)
    {
        case SDL_QUIT:
            isRunning = false;
            break;
    }
}

void Game::showScoreNotice(const int _score)
{
    notifiLayer = new NotificationLayer(_score);
    gameState = SHOW_SCORE;
    //delete layer;
    layer = nullptr;
    std::cout << "show score" << std::endl;
}

void Game::playSinglyMode()
{
    layer = new Layer();
    gameState = PLAY_MODE_1;
    notifiLayer = nullptr;
    std::cout << "play" << std::endl;
}


void Game::clean()
{
    SDL_DestroyWindow(window);
    SDL_DestroyRenderer(renderer);
    TTF_Quit();
    IMG_Quit();
    SDL_Quit();
    std::cout << "Quit SDL" << std::endl;
}
