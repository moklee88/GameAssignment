#pragma once

#include "GameState.h"
#include <vector>
#include "FrameTimer.h"

#define GAME_FPS 20

class GameStateManager
{
private:
	static GameStateManager* sInstance;
	GameStateManager();
	~GameStateManager();

	FrameTimer* timer;
	int framesToUpdate;

public:
	static GameStateManager* getInstance();
	static void releaseInstance();

	int currentState;

	std::vector<GameState*> stateList;

	//Start screen
	void update();
	void draw();


};
