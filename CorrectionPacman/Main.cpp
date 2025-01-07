#include "CoreMinimal.h"
#include "fileLoader.h"
#include "Entity.h"
#include "Level.h"
#include "InputManager.h"

int main()
{
    _CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);

    Level _level = Level("SmallMap");

    RenderWindow _window(VideoMode(_level.GetMapSize()), "pacman");

    while (_window.isOpen())
    {
        InputManager::GetInstance().ConsumeInput(_window);

        _window.clear();
        _level.Display(_window);
        _window.display();
    }

    return 0;
}

//1 - lecture fichier txt
//2 - génération Entité
//3 - boucle affichage entité