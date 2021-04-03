#pragma warning(disable : 4996)

#include "EnemyController.h"

#include <stdio.h>

//singleton
EnemyController* EnemyController::sInstance = NULL;

EnemyController* EnemyController::getInstance()
{
	if (EnemyController::sInstance == NULL)
	{
		sInstance = new EnemyController(&Spawner::getInstance()->spawnList);
	}

	return sInstance;
}

void EnemyController::releaseInsrance()
{
	delete sInstance;
	sInstance = NULL;
}

EnemyController::EnemyController(std::vector<Character*> *spawnList)
{
	this->spawnList = *spawnList;
}

EnemyController::~EnemyController()
{
	release();
}


void EnemyController::fixedUpdate()
{
	//fix update the enemy

	for (int i = 0; i < spawnList.size(); i++)
	{
		spawnList[i]->physic();
	}
}

void EnemyController::update()
{
	// handle remove object and enemy


}


void EnemyController::release()
{

	for (int i = 0; i < spawnList.size(); i++)
	{
		delete spawnList[i];
		spawnList[i] = NULL;
	}

	minionTexture->Release();
	minionTexture = NULL;

	bossTexture->Release();
	bossTexture = NULL;
}