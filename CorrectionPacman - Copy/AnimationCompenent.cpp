#include "AnimationCompenent.h"

AnimationCompenent::AnimationCompenent(Entity* _owner, const Vector2i& _spriteSize, const Vector2i& _grid,
					const float _speed, const bool _isLoop)
					: Compenent(_owner)
{
	canRun = false;
	spriteSize =  _spriteSize;
	grid = _grid;
	speed = _speed;
	isLoop = _isLoop;
	currentFrame = Vector2i(0,0);
	shape = owner->GetShapePtr();
}

void AnimationCompenent::ChangeNextFrame()
{
	++currentFrame.x;
	if (currentFrame.x >= grid.x)
	{
		if (isLoop)
		{
			currentFrame.x = 0;
		}
		else
		{
			canRun = false;
			return;
		}
	}

	TextureManager::GetInstance().SetTextureRectOnShape(*shape, ComputeFrameRect());

}

IntRect AnimationCompenent::ComputeFrameRect()
{
	const Vector2i& _tileSize = Vector2i(spriteSize.x / grid.x, spriteSize.y / grid.y);
	const Vector2i& _position = Vector2i((currentFrame.x - 1) * _tileSize.x, (currentFrame.y - 1) * _tileSize.y);
	return IntRect(_position, _tileSize);
}

void AnimationCompenent::Reset()
{
	currentFrame = Vector2i(0, 0);
}

void AnimationCompenent::Update()
{
	Compenent::Update();
	ChangeNextFrame();
}

void AnimationCompenent::SetCurrentFrame(const Vector2i& _frame)
{
	TextureManager::GetInstance().SetTextureRectOnShape(*shape, ComputeFrameRect());
}
