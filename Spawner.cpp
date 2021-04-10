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
	spawnList = NULL;
	platformList = NULL;
	coinList = NULL;
	spawnSpeed = NULL;
	spawnTime = NULL;

	position = { NULL,NULL,NULL };
}

void Spawner::update()
{
	//spawner delay
	spawnSpeed = (rand() % (20));
	position.x = 700;
	position.y = (rand() % 250) + 100;


	spawnTime += (0.001f) * spawnSpeed;
	if (spawnTime > 1)
	{
		Character* enemy = new Character();

		(*spawnList).push_back(enemy);

		Platform* platform = new Platform(position, -120, 156, 11, 588, 0);
		(*platformList).push_back(platform);

		position.y = (rand() % 240) + 100;

		Coins* coin = new Coins(position, -120, 35, 35, 0, 194);
		(*coinList).push_back(coin);

		spawnTime = 0;

	}

}
