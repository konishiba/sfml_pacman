#include "Game.h"
#include "InputManager.h"

#define MAP_SIZE_X 28
#define MAP_SIZE_Y 12
#define TILE_SIZE 20


Game::Game()
{
	window = new RenderWindow(VideoMode(Vector2u(MAP_SIZE_X * TILE_SIZE, MAP_SIZE_Y * TILE_SIZE)), "pacman");
    score = 0;
}

Game::~Game()
{
    delete window;
    delete level;
}

void Game::Launch(string _mapName)
{
    level = new Level(_mapName, window);
    GameLoop();
}


void Game::GameLoop()
{
    while (window->isOpen())
    {
        InputManager::GetInstance().ConsumeInput(*window);

        window->clear();
        level->Update();
        window->display();
        SLEEP(100ms);
    }
}
