#pragma once
#include "Compenent.h"

class MovementCompenent : public Compenent
{
	int speed;

public:

	MovementCompenent(Entity* _owner, int _speed);

	void Move(Vector2i _direction);
};

