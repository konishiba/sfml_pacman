#pragma once
#include "CoreMinimal.h"
#include "Entity.h"
#include "Compenent.h"

class AnimationCompenent : public Compenent
{
	bool canRun;
	float speed;
	bool isLoop;
	Vector2i spriteSize;
	Vector2i grid;
	Vector2i currentFrame;
	RectangleShape* shape;

public:
	inline void ToggleRunStatus()
	{
		canRun = !canRun;
	}

	inline void SetCurrentRow(const int _rowIndex)
	{
		currentFrame.y = _rowIndex;
	}
public:
	AnimationCompenent(Entity* _owner,const Vector2i& _spriteSize,const Vector2i& _grid, const float _speed = false ,const bool _isLopp = false);
private:
	void ChangeNextFrame();
	IntRect ComputeFrameRect();
	void Reset();
public:
	virtual void Update() override;
	void SetCurrentFrame(const Vector2i& _frame);
};

