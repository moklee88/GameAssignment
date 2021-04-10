#include "GameStateManager.h"
#include "GameMenu.h"
#include "Scene.h"
#include "GameOver.h"

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

	GameMenu* menu = new GameMenu();
	stateList.push_back(menu);

	Scene* level = new Scene();
	stateList.push_back(level);

	GameOver* gameOver = new GameOver();
	stateList.push_back(gameOver);

	timer = new FrameTimer();
	timer->init(GAME_FPS);
	framesToUpdate = 0;
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

