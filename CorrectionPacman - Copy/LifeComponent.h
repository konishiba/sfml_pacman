#pragma once
#include "Component.h"

class LifeComponent : public Component
{
	int lifesCount;
public:

	bool IsAlive() const
	{
		return lifesCount > 0;
	}

	//TODO to remove
	void SetLife(int _life)
	{
		lifesCount = _life;
	}

public:

	LifeComponent(Entity* _owner);

public:

	void RemoveLife();
	void ResetLife();
};

