#pragma once
#include "FrameTimer.h"
#include "GameState.h"
#include "Scene.h"
#include <vector>

#define GAME_FPS 20

class GameStateManager
{
private:
	static GameStateManager* sInstance;
	GameStateManager();
	~GameStateManager();

public:
	static GameStateManager* getInstance();
	static void releaseInstance();

	FrameTimer* timer;

	int currentState;
	float framesToUpdate;
	std::vector<GameState*> stateList;

	//Start screen
	void update();
	void draw();


};
