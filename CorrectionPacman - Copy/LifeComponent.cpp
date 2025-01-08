#include "LifeComponent.h"

LifeComponent::LifeComponent(Entity* _owner) : Component(_owner)
{
	ResetLife();
}

void LifeComponent::RemoveLife()
{
	lifesCount--;
	lifesCount = lifesCount == 0 ? 0 : lifesCount;
}

void LifeComponent::ResetLife()
{
	lifesCount = 3;
}
