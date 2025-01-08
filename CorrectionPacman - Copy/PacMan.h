#pragma once
#include "CoreMinimal.h"
#include "Entity.h"
#include "MovementComponent.h"
#include "LifeComponent.h"

class PacMan : public Entity
{
	MovementComponent* movement;
	LifeComponent* life;

public:
	inline MovementComponent* GetMovementComponent()const
	{
		return movement;
	}

public:
	PacMan(Level* _level, const Vector2f& _shapeSize);
	~PacMan();

public:
	virtual void Update() override;
	void AddPoint(const int _points);
private:
	void SetupInput();
	virtual void UpdateMoveAnimation() override;
	virtual void DeadAnimation() override;

};