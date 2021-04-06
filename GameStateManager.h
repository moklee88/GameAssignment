#pragma once

#include "GameMenu.h"
#include "Scene.h"
#include "GameState.h"
#include <vector>

class GameStateManager
{
private:
	static GameStateManager* sInstance;
	GameStateManager();
	~GameStateManager();

public:
	static GameStateManager* getInstance();
	static void releaseInstance();

	int currentState;

	std::vector<GameState*> stateList;

	//Start screen
	void update();
	void draw();


};
