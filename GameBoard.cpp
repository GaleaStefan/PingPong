#include "GameBoard.h"
#include "Player.h"


GameBoard::GameBoard(GameEngine* _engine) :
	GameObject(_engine)
{
}

void GameBoard::Draw() const
{
	olc::vi2d midTop{ engine->GetAbsoluteHorizontal(0.5f), engine->GetAbsoluteVertical(0.f) };
	olc::vi2d midBottom{ engine->GetAbsoluteHorizontal(0.5f), engine->GetAbsoluteVertical(1.f) };
	engine->DrawLine(midTop, midBottom);

	std::string redScore = std::to_string(engine->GetRedPlayer()->GetScore());
	std::string blueScore = std::to_string(engine->GetBluePlayer()->GetScore());
	engine->DrawString(olc::vi2d(midTop.x - 17, 5), redScore, olc::RED, 2);
	engine->DrawString(olc::vi2d(midTop.x + 5, 5), blueScore, olc::BLUE, 2);
}
