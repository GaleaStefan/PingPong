#include "GameObject.h"

GameObject::GameObject(GameEngine* _e) :
	engine(_e),
	position(),
	direction()
{
}

GameObject::GameObject(const olc::vf2d& _pos, const olc::vf2d& _dir, GameEngine* _e) :
	position(_pos),
	direction(_dir),
	engine(_e)
{
}

GameObject::~GameObject()
{
	engine = nullptr;
}

void GameObject::MoveAt(const olc::vf2d& _newPos)
{
	position = _newPos;
}
