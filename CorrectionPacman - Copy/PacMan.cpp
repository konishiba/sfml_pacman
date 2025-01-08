#include "PacMan.h"
#include "InputManager.h"
PacMan::PacMan(Level* _level, const Vector2f& _shapeSize) : Entity(_level, "Pacman/Moving/PacMan_Eating", _shapeSize)
{
	movement = new MovementComponent(this);
	life = new LifeComponent(this);
	shape.setTextureRect(IntRect(Vector2i(0, 0), Vector2i(15, 15)));
	SetupInput();
}

PacMan::~PacMan()
{
	delete movement;
	delete life;
}

void PacMan::SetupInput()
{
	InputManager& _inputManager = InputManager::GetInstance();
	_inputManager.BindAction([&]() { movement->ToggleMoveStatus(); }, Code::Space);
	_inputManager.BindAction([&]() { movement->SetDirection(Vector2i(0, -1)); }, { Code::Z, Code::Up });
	_inputManager.BindAction([&]() { movement->SetDirection(Vector2i(0, 1)); }, { Code::S, Code::Down });
	_inputManager.BindAction([&]() { movement->SetDirection(Vector2i(-1, 0)); }, { Code::Q, Code::Left });
	_inputManager.BindAction([&]() { movement->SetDirection(Vector2i(1, 0)); }, { Code::D, Code::Right });
}

void PacMan::UpdateMoveAnimation()
{
	IntRect _currentIntRect = shape.getTextureRect();
	Vector2u _sheetSize = shape.getTexture()->getSize(), _spriteOffset = { _sheetSize.y,0 };
	_currentIntRect.position = _currentIntRect.position != Vector2i(_sheetSize.x - _spriteOffset.x, 0)
							 ? _currentIntRect.position + Vector2i(_spriteOffset) : Vector2i(0, 0);
	shape.setTextureRect(_currentIntRect);
}

void PacMan::DeadAnimation()
{
	TextureManager::GetInstance().InitShape(shape, texture, "Pacman/Dying/PacMan_Dying");
	IntRect _currentIntRect = shape.getTextureRect();
	Vector2u _sheetSize = shape.getTexture()->getSize(), _spriteOffset = { _sheetSize.y,0 };
	_currentIntRect.position = _currentIntRect.position + Vector2i(_spriteOffset);
	shape.setTextureRect(_currentIntRect);
}

void PacMan::Update()
{
	movement->Update();
	life->Update();
}

void PacMan::AddPoint(const int _points)
{
	level->AddScore(_points);
}
