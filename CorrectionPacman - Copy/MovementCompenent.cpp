#include "MovementCompenent.h"

MovementCompenent::MovementCompenent(Entity* _owner, int _speed) : Compenent(owner)
{
	speed = _speed;
}

void MovementCompenent::Move(Vector2i _direction)
{
	owner->GetShape().move(Vector2f(_direction * speed));
}
