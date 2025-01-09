#include "PacMan.h"
#include "InputManager.h"
PacMan::PacMan(Level* _level, const Vector2f& _shapeSize) : Entity(_level, "Pacman/Moving/PacMan_Eating", _shapeSize)
{
	movement = new MovementComponent(this);
	life = new LifeComponent(this);
	animation = new AnimationCompenent(this, Vector2i(texture.getSize()), Vector2i(3,1));
	animation->SetCurrentFrame({0,0});
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
	_inputManager.BindAction([&]() { movement->ToggleMoveStatus(); animation->ToggleRunStatus(); }, Code::Space);
	_inputManager.BindAction([&]() { life->SetLife(0); }, Code::K);
	_inputManager.BindAction([&]() { movement->SetDirection(Vector2i(0, -1));  }, { Code::Z, Code::Up });
	_inputManager.BindAction([&]() { movement->SetDirection(Vector2i(0, 1)); }, { Code::S, Code::Down });
	_inputManager.BindAction([&]() { movement->SetDirection(Vector2i(-1, 0)); }, { Code::Q, Code::Left });
	_inputManager.BindAction([&]() { movement->SetDirection(Vector2i(1, 0)); }, { Code::D, Code::Right });
}

void PacMan::Update()
{
	if (!life->IsAlive())
	{
		movement->SetMoveStatus(false);
	}
	movement->Update();
	life->Update();
	animation->Update();
}

