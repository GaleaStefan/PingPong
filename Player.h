#pragma once

#include "GameObject.h"

class Player : public GameObject
{
public:
	enum class MoveDirection
	{
		UP, DOWN
	};
public:
	//Player();
	Player(float, const olc::vf2d&, const olc::vf2d&, const olc::Pixel&, GameEngine*);
	~Player() = default;

	void		Draw() const override;
	void		Move(MoveDirection, float);

	olc::vf2d	GetPosition() const;

	olc::vf2d	GetSize() const;

	float		GetMoveSpeed() const;

	int32_t		GetScore() const;
	void		SetScore(int32_t);
private:
	float		moveSpeed;
	olc::vf2d	size;
	olc::Pixel	color;
	int32_t		score;
};

