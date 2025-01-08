#include "Entity.h"


Entity::Entity(const string& _name, Vector2f _shapeSize)
{
	shapeSize = _shapeSize;
	shape = new RectangleShape(shapeSize);
	TextureManager::GetInstance().InitShape(*shape, texture,_name);
	shape->setOrigin({ shapeSize.x / 2 , shapeSize.y / 2});
}

Entity::~Entity()
{
	delete shape;
}

void Entity::Update()
{
}
