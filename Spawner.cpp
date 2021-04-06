#include "Spawner.h"
#include <stdio.h>

Spawner::Spawner()
{

}
Spawner::Spawner(std::vector<Character*>* spawnList)
{
	this->spawnList = spawnList;
	spawnSpeed = 6;
	spawnTime = 0;
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
		Character* enemy = new Character();

		(*spawnList).push_back(enemy);

		spawnTime = 0;
	}

}
