#pragma once
#include <d3dx9.h>
#include <vector>

#include "Character.h"


class Spawner
{
private:
	

public:
	Spawner();
	Spawner(std::vector<Character*>* spawnList);
	~Spawner();
	std::vector<Character*>* spawnList;
	void init();
	void update();

	int spawnSpeed;
	float spawnTime;
};

