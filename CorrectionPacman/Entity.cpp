#include "Entity.h"


Entity::Entity(const string& _name, Vector2f _shapeSize)
{
	shapeSize = _shapeSize;
	shape = RectangleShape(shapeSize);
	TextureManager::GetInstance().InitShape(shape, texture,_name);
}
