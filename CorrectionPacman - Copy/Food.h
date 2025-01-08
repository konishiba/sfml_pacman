#pragma once
#include "Entity.h"

class Food : public Entity
{
public:
	Food(const string& _name, Vector2f _shapeSize);

private:
	virtual void UpdateMoveAnimation() override;
};

