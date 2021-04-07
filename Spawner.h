#pragma once
#include <d3dx9.h>
#include <vector>

#include "Character.h"
#include "Platform.h"
#include "Coins.h"

class Spawner
{
private:
	D3DXVECTOR3 position;

public:
	Spawner();
	Spawner(std::vector<Character*>* spawnList, std::vector<Platform*>* platformtList, std::vector<Coins*>* coinList);
	~Spawner();
	std::vector<Character*>* spawnList;
	std::vector<Platform*>* platformList;
	std::vector<Coins*>* coinList;

	void init();
	void update();

	int spawnSpeed;
	float spawnTime;
};

