#pragma once
#include "Entity.h"

class Wall : public Entity
{
public:
	Wall(const string& _name, Vector2f _shapeSize);

private:
	virtual void UpdateMoveAnimation() override;
};

