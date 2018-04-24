#include "Game.h"
#include "Player.h"
#include "Sprite.h"

SDL_Renderer* Game::renderer = nullptr;
SDL_Event Game::event;

Game::Game()
{

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
            SDL_SetRenderDrawColor(renderer, 40, 46, 58, 255);
            std::cout << "Renderer created!" << std::endl;
        }

        _isRunning = true;
    }
    else
    {
        _isRunning = false;
    }

}

void Game::update()
{
    dt++;
    listenEvents();
    std::cout << dt << std::endl;
}

void Game::listenEvents()
{
    SDL_PollEvent(&event);

    switch (event.type)
    {
        case SDL_QUIT:
            _isRunning = false;
            break;

    }
}

void Game::render()
{
    SDL_RenderClear(renderer);
    //player->sprite->render();
    SDL_RenderPresent(renderer);
}

void Game::clean()
{
    SDL_DestroyWindow(window);
    SDL_DestroyRenderer(renderer);
    SDL_Quit();
    std::cout << "Quit SDL" << std::endl;
}
