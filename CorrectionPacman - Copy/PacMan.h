#pragma once
#include "CoreMinimal.h"
#include "Entity.h"
#include "MovementComponent.h"
#include "LifeComponent.h"
#include "AnimationCompenent.h"

class PacMan : public Entity
{
	MovementComponent* movement;
	LifeComponent* life;
	AnimationCompenent* animation;

public:
	inline MovementComponent* GetMovementComponent()const
	{
		return movement;
	}
	inline LifeComponent* GetLifeComponent() const
	{
		return life;
	}

public:
	PacMan(Level* _level, const Vector2f& _shapeSize);
	~PacMan();

public:
	virtual void Update() override;
private:
	void SetupInput();

};