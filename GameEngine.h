#pragma once

#include "Dependencies/olcPixelGameEngine.h"

class GameBoard;
class Player;
class Ball;

class GameEngine :
    public olc::PixelGameEngine
{
public:
    GameEngine();
    ~GameEngine();

    bool    OnUserCreate() override;
    bool    OnUserUpdate(float deltaTime) override;
    void    OnPlayerScore(Player* p);

    int32_t GetAbsoluteHorizontal(float relativeValue) const;
    int32_t GetAbsoluteVertical(float relativeValue) const;

    Player* GetRedPlayer() const;
    Player* GetBluePlayer() const;

private:
    GameBoard*  gameBoard;
    Player*     redPlayer;
    Player*     bluePlayer;
    Ball*       ball;
    bool        gameRunning;
    float       timer;
};

