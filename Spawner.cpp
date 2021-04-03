#include "Spawner.h"

#include <stdio.h>

Spawner* Spawner::sInstance = NULL;

Spawner* Spawner::getInstance()
{
	if (Spawner::sInstance == NULL)
	{
		sInstance = new Spawner;
	}

	return sInstance;
}

void Spawner::releaseInsrance()
{
	delete sInstance;
	sInstance = NULL;
}


Spawner::Spawner()
{
	spawnSpeed = 6;
}

Spawner::~Spawner()
{

}

void Spawner::init()
{
	
}

void Spawner::update()
{
	//spawner delay

	spawnTime += (0.001f) * spawnSpeed;
	if (spawnTime > 1)
	{
		enemy = new Character();

		spawnList.push_back(enemy);

		spawnTime = 0;
	}

}
