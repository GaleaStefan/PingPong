#include "GameEngine.h"
#include "GameBoard.h"
#include "Player.h"
#include "Ball.h"

GameEngine::GameEngine()
{
	sAppName = "Ping Pong";
}

GameEngine::~GameEngine()
{
	delete gameBoard;
	delete redPlayer;
	delete bluePlayer;
	delete ball;
}

bool GameEngine::OnUserCreate()
{
	gameRunning = false;
	timer = 0.f;

	gameBoard = new GameBoard(this);

	int32_t offset = 15;
	olc::vi2d playerRectSize{ 5, GetAbsoluteVertical(1.f / 5.f) };
	olc::vi2d redPos{ offset, GetAbsoluteVertical(0.5f) };
	redPlayer = new Player(100.f, redPos, playerRectSize, olc::RED, this);

	olc::vi2d bluePos { GetAbsoluteHorizontal(1.f) - offset, redPos.y };
	bluePlayer = new Player(100.f, bluePos, playerRectSize, olc::BLUE, this);

	ball = new Ball(200.0f, 0.8f, { (float)GetAbsoluteHorizontal(0.5f), (float)GetAbsoluteVertical(0.5f) }, 5, this);
	return true;
}

bool GameEngine::OnUserUpdate(float deltaTime)
{
	Clear(olc::BLACK);

	if (!gameRunning)
	{
		DrawString(0, 0, "Press Space to continue", olc::WHITE, 2);

		if (GetKey(olc::Key::SPACE).bPressed)
		{
			gameRunning = true;
		}

		return true;
	}

	// Game board
	gameBoard->Draw();

	// Players
	auto attemptPlayerMove = [this, deltaTime](Player* player, olc::Key upKey, olc::Key downKey)
	{
		if (GetKey(upKey).bHeld)
		{
			player->Move(Player::MoveDirection::UP, deltaTime);
		}

		if (GetKey(downKey).bHeld)
		{
			player->Move(Player::MoveDirection::DOWN, deltaTime);
		}

		player->Draw();
	};

	attemptPlayerMove(redPlayer, olc::Key::W, olc::Key::S);
	attemptPlayerMove(bluePlayer, olc::Key::UP, olc::Key::DOWN);

	// Ball
	ball->Move(deltaTime);
	ball->Draw();

	// Timer - Increase the ball speed every 10 units
	timer += deltaTime;

	if (timer >= 10.f)
	{
		ball->SetSpeed(ball->GetSpeed() + 20.f);
		timer = 0.f;
	}
	return true;
}

void GameEngine::OnPlayerScore(Player* p)
{
	p->SetScore(p->GetScore() + 1);
	ball->MoveAt({ (float)GetAbsoluteHorizontal(0.5f), (float)GetAbsoluteVertical(0.5f) });
	gameRunning = false;
}

int32_t GameEngine::GetAbsoluteHorizontal(float relativeValue) const
{
	return relativeValue * ScreenWidth();
}

int32_t GameEngine::GetAbsoluteVertical(float relativeValue) const
{
	return relativeValue * ScreenHeight();
}

Player* GameEngine::GetRedPlayer() const
{
	return redPlayer;
}

Player* GameEngine::GetBluePlayer() const
{
	return bluePlayer;
}
