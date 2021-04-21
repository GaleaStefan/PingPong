#pragma once

#include "GameObject.h"

class Ball : public GameObject
{
public:
	Ball(float _moveSpeed, float angle, const olc::vf2d& position, int radius, GameEngine* _e);

	void	Draw() const override;
	void	Move(float deltaTime);

	bool	IsInCollisionWith(Player* p) const;

	float	GetSpeed() const;
	void	SetSpeed(float);
private:
	float	moveSpeed;
	int32_t	radius;
};

