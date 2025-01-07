#pragma once
#include "CoreMinimal.h"
#include "FileLoader.h"
#include "PacMan.h"

class Level
{
	string name;
	string prefixPath;
	vector<Entity*> entities;
	Vector2u mapSize;
public:

	inline Vector2u GetMapSize() const
	{
		return mapSize;
	}


public:
	Level(const string& _name);

	~Level();

private:
	void Generate();
	void SpawnEntity(const char& _symbol, const Vector2f _coords, Vector2f& _shapeSize);
	void PlaceEntity(Vector2i _coords, Vector2f& _shapeSize, Entity* _entity);
public:
	void Display(RenderWindow& _window) const;
};

