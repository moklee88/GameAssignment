#include "GameStateManager.h"
#include "GameMenu.h"
#include "Scene.h"

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

	//GameMenu* menu = new GameMenu();
	//stateList.push_back(menu);

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

}


void GameStateManager::update()
{
	stateList[currentState]->update();


	stateList[currentState]->fixUpdate();


}

void GameStateManager::draw()
{
	stateList[currentState]->draw();
}

