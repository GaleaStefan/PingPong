#pragma once

#include "GameEngine.h"

class GameObject
{
public:
			GameObject(GameEngine*);
			GameObject(const olc::vf2d&, const olc::vf2d&, GameEngine*);
	virtual	~GameObject();

	virtual void Draw() const = 0;
			void MoveAt(const olc::vf2d&);
protected:
	olc::vf2d	position;
	olc::vf2d	direction;
	GameEngine* engine;
};

