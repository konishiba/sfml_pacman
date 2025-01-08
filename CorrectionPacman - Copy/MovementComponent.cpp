#include "MovementComponent.h"

MovementComponent::MovementComponent(Entity* _owner) : Component(_owner)
{
	canMove = false;
	speed = 1;
}

void MovementComponent::Update()
{
	Move();
}

void MovementComponent::Move()
{
	if (!canMove) return;

	cout << direction.x << "->" << direction.y << endl;
	const float _x = direction.x * speed * owner->GetShapeSize().x;
	const float _y = direction.y * speed * owner->GetShapeSize().y;

	RectangleShape* _shape = owner->GetShape();
	const Vector2f& _destination = _shape->getPosition() + Vector2f(_x, _y);

	if (Entity* _entity = owner->GetLevel()->CheckCollision(_destination))
	{
		_entity->CheckCollision()->Collide();
		return;
	}

	owner->GetShape()->move(_destination);
	owner->UpdateMoveAnimation();
}
 
void MovementComponent::Rotate(float _radians)
{
	owner->GetShape()->setRotation(radians(_radians));
}

void MovementComponent::Rotate(const Vector2i& _direction)
{
	RectangleShape* _shape = owner->GetShape();
	const float _angle = _direction.y != 0 ? 90.0f * _direction.y :
						_direction.x < 0 ? 180.0f : 0.0f;

	if (_direction.y != 0)
	{
		owner->GetShape()->rotate(degrees(90.0f * _direction.y));
	}
	else if (_direction.x < 0)
	{
		owner->GetShape()->rotate(degrees(180.0f));
	}
	else
	{
		owner->GetShape()->setRotation(degrees(0.0f));
	}
}
