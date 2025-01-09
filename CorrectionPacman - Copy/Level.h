#pragma once
#include "CoreMinimal.h"

class PacMan;
class Entity;

class Level
{
	string name;
	string prefixPath;
	vector<Entity*> entities;
	Vector2u mapSize;
	RenderWindow* window;
	int points;

public:

	inline Vector2u GetMapSize() const
	{
		return mapSize;
	}


public:
	Level() = default;
	Level(const string& _name, RenderWindow* _window);
	~Level();

public:
	void Update();
	Entity* CheckCollision(const Vector2f& _targetPosition);

private:
	void Generate();
	void SpawnEntity(const char& _symbol, const Vector2f _coords, Vector2f& _shapeSize);
	void PlaceEntity(Vector2i _coords, Vector2f& _shapeSize, Entity* _entity);
	void Display() const;

public:
};

