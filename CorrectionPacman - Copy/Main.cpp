#include "CoreMinimal.h"
#include "fileLoader.h"
#include "Entity.h"
#include "Level.h"
#include "InputManager.h"
#include "Object.h"
#include "Game.h"

#define MAP_SIZE_X 28
#define MAP_SIZE_Y 12
#define TILE_SIZE 20

int main()
{
    _CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);

    Game::GetInstance().Launch("SmallMap");

    return 0;
}

//1 - lecture fichier txt
//2 - génération Entité
//3 - boucle affichage entité