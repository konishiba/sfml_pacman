#include "PacMan.h"
#include "InputManager.h"
PacMan::PacMan(const string& _name, const Vector2f& _shapeSize) : Entity(_name, _shapeSize)
{
	movement = new MovementComponent(this);
	life = new LifeComponent(this);
	shape->setTextureRect(IntRect(Vector2i(0, 0), Vector2i(15, 15)));
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
	_inputManager.BindAction({ Code::Space }, [&]() { movement->ToggoleMoveStatus();/* movement->Rotate(3*M_PI/2);*/ });
	_inputManager.BindAction({ Code::Z }, [&]() { movement->SetDirection(Vector2i(0, -1));/* movement->Rotate(3*M_PI/2);*/ });
	_inputManager.BindAction({ Code::S }, [&]() { movement->SetDirection(Vector2i(0, 1));/* movement->Rotate(M_PI / 2);*/ });
	_inputManager.BindAction({Code::Q}, [&]() { movement->SetDirection(Vector2i(-1, 0)); /*movement->Rotate(M_PI);*/ });
	_inputManager.BindAction({ Code::D }, [&]() { movement->SetDirection(Vector2i(1, 0)); /* movement->Rotate(0);*/ });
}

void PacMan::UpdateMoveAnimation()
{
	Vector2i _vec = Vector2i(15, 0);
	IntRect _currentIntRect = shape->getTextureRect();
	IntRect _newIntRect = _currentIntRect;
	_newIntRect.position = _newIntRect.position != Vector2i(30, 0) ? _newIntRect.position + _vec : Vector2i(0, 0);
	shape->setTextureRect(_newIntRect);
}

void PacMan::Update()
{
	movement->Update();
	life->Update();
}

