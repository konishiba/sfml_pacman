#include "CollisionComponent.h"

CollisionComponent::CollisionComponent(Entity* _owner, SolidType _solid) : Component(_owner)
{
	solid = _solid;
}

void CollisionComponent::Collide(const function<void()>& _callback)
{
}
