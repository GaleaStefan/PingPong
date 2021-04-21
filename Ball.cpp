#include "Ball.h"
#include <cmath>
#include "Player.h"

Ball::Ball(float _moveSpeed, float angle, const olc::vf2d& _position, int _radius, GameEngine* _e) :
	GameObject(_position, { std::cos(angle), std::sin(angle) }, _e),
	moveSpeed(_moveSpeed),
	radius(_radius)
{
	direction.norm();
}

void Ball::Draw() const
{
	engine->FillCircle(position, radius, olc::GREY);
}

void Ball::Move(float deltaTime)
{
	// Screen collision
	if (position.y + radius <= 0.f || position.y + radius >= engine->ScreenHeight())
	{
		direction.y *= -1;
	}

	// Players collisions
	if (IsInCollisionWith(engine->GetRedPlayer()) || IsInCollisionWith(engine->GetBluePlayer()))
	{
		direction.x *= -1;
	}

	// Scored detection
	if (position.x - radius <= 0)
	{
		// Blue scored
		engine->OnPlayerScore(engine->GetBluePlayer());
	}

	if (position.x + radius >= engine->ScreenWidth())
	{
		// Red scored
		engine->OnPlayerScore(engine->GetRedPlayer());
	}

	// Move the ball
	position += direction * moveSpeed * deltaTime;
}

bool Ball::IsInCollisionWith(Player* p) const
{
	olc::vf2d playerPos = p->GetPosition();
	olc::vf2d playerSize = p->GetSize();

	auto isBetween = [](float number, float radius, float lowerBound, float upperBound)
	{
		return number >= lowerBound && number <= upperBound;
	};

	if (isBetween(position.y, 0, playerPos.y - playerSize.y, playerPos.y + playerSize.y) &&
		isBetween(position.x, radius, playerPos.x - playerSize.x / 2, playerPos.x + playerSize.x / 2))
	{
		return true;
	}

	return false;
}

float Ball::GetSpeed() const
{
	return moveSpeed;
}

void Ball::SetSpeed(float speed)
{
	moveSpeed = speed;
}
