#pragma once
#include "TextureManager.h"
#include "Object.h"
#include "Level.h"

class Entity : public Object
{
protected:
	Level* level;
	Vector2f shapeSize;
	RectangleShape* shape;
	Texture texture;

public:
	inline void SetPosition(const Vector2f& _coords)
	{

		shape->setPosition(_coords);
	}

	inline RectangleShape* GetShape() const
	{
		return shape;
	}
	inline Vector2f GetShapeSize() const
	{
		return shapeSize;
	}
	inline Vector2f GetPosition() const
	{
		return shape->getPosition();
	}
	inline Level* GetLevel() const
	{
		return level;
	}

	Entity(const string& _name, Vector2f _shapeSize);

	~Entity();

public:
	virtual void Update() override;

	virtual void UpdateMoveAnimation() = 0;


};

