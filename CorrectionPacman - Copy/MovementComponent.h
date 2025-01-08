#pragma once
#include "Component.h"

class MovementComponent : public Component
{
	bool canMove;
	int speed;
	Vector2i direction;

public:
	inline void ToggoleMoveStatus()
	{
		canMove = !canMove;
	}

	inline void SetDirection(const Vector2i& _newDirection)
	{
		if (!canMove) return;

		if (_newDirection != direction)
		{
			Rotate(_newDirection);	
		}
		direction = _newDirection;
	}

public:
	MovementComponent(Entity* _owner);

	virtual void Update() override;

	void Move();
public:

	void Rotate(float _radians);

	void Rotate(const Vector2i& _direction);

};

