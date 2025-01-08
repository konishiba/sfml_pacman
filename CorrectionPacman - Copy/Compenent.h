#pragma once
#include "Entity.h"

class Compenent
{
protected:
	Entity* owner;

public:
	inline Entity* GetOwner() const
	{
		return owner;
	}

public:
	Compenent(Entity* _owner);
};

