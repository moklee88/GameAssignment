#include "GameStateManager.h"

GameStateManager* GameStateManager::sInstance = NULL;

GameStateManager* GameStateManager::getInstance()
{
	if (GameStateManager::sInstance == NULL)
	{
		sInstance = new GameStateManager;
	}

	return sInstance;
}

void GameStateManager::releaseInstance()
{
	delete sInstance;
	sInstance = NULL;
}

GameStateManager::GameStateManager()
{
	currentState = 0;

	timer = new FrameTimer();
	timer->init(GAME_FPS);
	framesToUpdate = 0;

	GameMenu* menu = new GameMenu();
	stateList.push_back(menu);

	Scene* level = new Scene();
	stateList.push_back(level);
}

GameStateManager::~GameStateManager()
{
	stateList[currentState]->release();

	for (int i = 0; i < stateList.size(); i++)
	{
		delete stateList[i];
		stateList[i] = NULL;
	}

	delete timer;
}


void GameStateManager::update()
{
	stateList[currentState]->update();

	framesToUpdate = timer->framesToUpdate();

	for (int i = 0; i < framesToUpdate; i++)
	{
		stateList[currentState]->fixUpdate();
	}

}

void GameStateManager::draw()
{
	stateList[currentState]->draw();
}

