#include "Spawner.h"
#include <stdio.h>

Spawner::Spawner()
{

}
Spawner::Spawner(std::vector<Character*>* spawnList, std::vector<Platform*>* platformList, std::vector<Coins*>* coinList)
{
	this->spawnList = spawnList;
	this->platformList = platformList;
	this->coinList = coinList;
	spawnSpeed = 6;
	spawnTime = 0;

	position = { NULL,NULL,NULL };
}

Spawner::~Spawner()
{

}

void Spawner::update()
{
	//spawner delay
	spawnSpeed = (rand() % (10));
	position.x = 700;
	position.y = (rand()%100);


	spawnTime += (0.001f) * spawnSpeed;
	if (spawnTime > 1)
	{
		Character* enemy = new Character();

		(*spawnList).push_back(enemy);

		Platform* platform = new Platform(position);
		(*platformList).push_back(platform);

		spawnTime = 0;

		//delete platform;
		//platform = NULL;
		//delete enemy;
		//enemy = NULL;
	}

}
