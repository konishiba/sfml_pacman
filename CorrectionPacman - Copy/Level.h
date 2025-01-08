#pragma once
#include "CoreMinimal.h"
#include "FileLoader.h"
#include "PacMan.h"
#include "Food.h"
#include "Ghost.h"
#include "Wall.h"

class Level
{
	string name;
	string prefixPath;
	vector<Entity*> entities;
	Vector2u mapSize;
	RenderWindow* window;
public:

	inline Vector2u GetMapSize() const
	{
		return mapSize;
	}


public:
	Level(const string& _name, RenderWindow* _window);
	~Level();

public:
	void Update();
private:
	void Generate();
	void SpawnEntity(const char& _symbol, const Vector2f _coords, Vector2f& _shapeSize);
	void PlaceEntity(Vector2i _coords, Vector2f& _shapeSize, Entity* _entity);
	void Display() const;

public:
	Entity* CheckCollision(const Vector2f& _targetPosition);
};

