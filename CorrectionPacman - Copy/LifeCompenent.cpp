#include "LifeCompenent.h"

LifeCompenent::LifeCompenent(Entity* _owner) : Compenent(_owner)
{
	ResetLife();
}

void LifeCompenent::RemoveLife()
{
	lifesCount--;
	lifesCount = lifesCount == 0 ? 0 : lifesCount;
}

void LifeCompenent::ResetLife()
{
	lifesCount = 3;
}
