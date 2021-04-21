#include "Player.h"

Player::Player(float _moveSpeed, const olc::vf2d& _pos, const olc::vf2d& _size, const olc::Pixel& _col, GameEngine* _eng) :
	GameObject(_pos, {0, 0}, _eng),
	moveSpeed(_moveSpeed),
	size(_size),
	color(_col),
	score(0)
{
}

void Player::Draw() const
{
	engine->FillRect(position - olc::vf2d{ size.x / 2.f, size.y / 2.f }, size, color);
}

void Player::Move(MoveDirection dir, float deltaTime)
{
	float offset = moveSpeed * deltaTime * (dir == MoveDirection::UP ? -1 : 1);
	float newY = position.y + offset;

	if (newY - size.y / 2 >= 0 &&
		newY + size.y / 2 <= engine->ScreenHeight())
	{
		position.y = newY;
	}
}

olc::vf2d Player::GetPosition() const
{
	return position;
}

olc::vf2d Player::GetSize() const
{
	return size;
}

float Player::GetMoveSpeed() const
{
	return moveSpeed;
}

int32_t Player::GetScore() const
{
	return score;
}

void Player::SetScore(int32_t _score)
{
	score = _score;
}
