#include "GameEngine.h"

int main()
{
	GameEngine pingPongEngine;

	if (pingPongEngine.Construct(512, 256, 2, 2, false))
	{
		pingPongEngine.Start();
	}

	return 0;
}