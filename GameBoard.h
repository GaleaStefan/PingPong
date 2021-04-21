#pragma once

#include "GameObject.h"

class GameBoard : public GameObject
{
public:
	GameBoard(GameEngine*);

	void Draw() const override;
};

