#include "CoreMinimal.h"
#include "fileLoader.h"
#include "Entity.h"
#include "Level.h"
#include "InputManager.h"
#include "Object.h"

#define MAP_SIZE_X 28
#define MAP_SIZE_Y 12
#define TILE_SIZE 20

int main()
{
    _CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);

    RenderWindow _window(VideoMode(Vector2u(MAP_SIZE_X * TILE_SIZE, MAP_SIZE_Y * TILE_SIZE)), "pacman");
    Level _level = Level("SmallMap", &_window);



    while (_window.isOpen())
    {
        InputManager::GetInstance().ConsumeInput(_window);

        _window.clear();
        _level.Update();
        _window.display();
        SLEEP(200ms);
    }

    return 0;
}

//1 - lecture fichier txt
//2 - génération Entité
//3 - boucle affichage entité