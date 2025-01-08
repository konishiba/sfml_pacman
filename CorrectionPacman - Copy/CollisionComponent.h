#pragma once
#include "Component.h"

enum SolidType
{
	ST_BLOCK,
	ST_OVERLAP,
	ST_NONE,

	ST_COUNT
};

class CollisionComponent : public Component
{
	SolidType solid;
public:
	CollisionComponent(Entity* _owner, SolidType _solid);

public:
	void Colide(const function<void()>& _callback);
};

