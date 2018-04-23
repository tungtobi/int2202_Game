#include "Game.h"

//SDL_Texture* spaceShip;

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
            SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
            std::cout << "Renderer created!" << std::endl;
        }

        _isRunning = true;
    }
    else
    {
        _isRunning = false;
    }

    //SDL_Surface* tmpSurface = IMG_Load("res/spaceShips_008.png");
    //spaceShip = SDL_CreateTextureFromSurface(renderer, tmpSurface);
    //SDL_FreeSurface(tmpSurface);
}

void Game::update()
{
    cnt++;

    std::cout << cnt << std::endl;
}

void Game::listenEvents()
{
    SDL_Event event;
    SDL_PollEvent(&event);

    switch (event.type)
    {
        case SDL_QUIT:
            _isRunning = false;
            break;

    }
}

void Game::render(Sprite spr)
{
    SDL_RenderClear(renderer);
    SDL_RenderCopy(renderer, spr.image, NULL, spr.dstRect);

    SDL_RenderPresent(renderer);
}

void Game::clean()
{
    SDL_DestroyWindow(window);
    SDL_DestroyRenderer(renderer);
    SDL_Quit();
    std::cout << "Quit SDL" << std::endl;
}

Sprite Game::addSprite(const char* path)
{
    Sprite sprite;

    SDL_Surface* tmpSurface = IMG_Load(path);
    sprite.image = SDL_CreateTextureFromSurface(renderer, tmpSurface);
    sprite.getContentSize(212, 160, 0.5);
    SDL_FreeSurface(tmpSurface);

    return sprite;
}
