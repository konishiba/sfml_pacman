#pragma once
#include "TextureManager.h"

class Entity
{
	Vector2f shapeSize;
	RectangleShape shape;
	Texture texture;
	Vector2i coords;

public:
	inline void SetPosition(const Vector2f& _coords)
	{

		shape.setPosition(_coords);
	}

	inline RectangleShape GetShape() const
	{
		return shape;
	}
	inline Vector2f GetShapeSize() const
	{
		return shapeSize;
	}

	Entity(const string& _name, Vector2f _shapeSize);
};

