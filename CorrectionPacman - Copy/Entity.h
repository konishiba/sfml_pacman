#pragma once
#include "TextureManager.h"
#include "Object.h"
#include "Level.h"
#include "CollisionComponent.h"

class Entity : public Object
{
	Vector2f shapeSize;
	CollisionComponent* collision;

protected:
	Texture texture;
	RectangleShape shape;
	Level* level;

public:
	inline void SetPosition(const Vector2f& _coords)
	{

		shape.setPosition(_coords);
	}

	inline RectangleShape& GetShape()
	{
		return shape;
	}
	inline Vector2f GetShapeSize() const
	{
		return shapeSize;
	}
	inline Vector2f GetPosition() const
	{
		return shape.getPosition();
	}
	inline Level* GetLevel() const
	{
		return level;
	}
	inline CollisionComponent* GetCollision() const
	{
		return collision;
	}

	Entity(Level* _level, const string& _name, const Vector2f& _shapeSize,
			const CollisionType& _type = CT_BLOCK, const function<void(Entity* _entity)>& _callback = {});

	~Entity();

public:
	virtual void Update() override;

	virtual void UpdateMoveAnimation();
	virtual void DeadAnimation();


};

