#pragma once
#include "Singleton.h"
#include "Level.h"
#include "Singleton.h"

class Game : public Singleton<Game>
{
	RenderWindow* window;
	Level* level;

	int score;
public:

	inline void AddScore(int _score)
	{
		score += _score;
	}

	Game();

	~Game();

	void Launch(string _mapName);

private:
	void GameLoop();
};

