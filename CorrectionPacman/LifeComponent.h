#pragma once
#include "Component.h"

class LifeComponent : public Component
{
	int lifesCount;
public:

	LifeComponent(Entity* _owner);

public:
	void RemoveLife();
	void ResetLife();
};

