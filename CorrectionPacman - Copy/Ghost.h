#pragma once
#include "Entity.h"

class Ghost : public Entity
{
public:
	Ghost(const string& _name, Vector2f _shapeSize);

private:
	virtual void UpdateMoveAnimation() override;
};

