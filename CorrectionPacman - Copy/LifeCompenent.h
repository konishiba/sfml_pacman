#pragma once
#include "Compenent.h"

class LifeCompenent : public Compenent
{
	int lifesCount;
public:

	LifeCompenent(Entity* _owner);

public:
	void RemoveLife();
	void ResetLife();
};

