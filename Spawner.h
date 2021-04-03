#ifndef SPAWNER
#define SPAWNER

#include <d3dx9.h>
#include <vector>

#include "Character.h"

class Spawner
{
private:
	static Spawner* sInstance;
	Character* enemy;

public:
	Spawner();
	~Spawner();

	static Spawner* getInstance();
	static void releaseInsrance();

	void init();
	void update();

	std::vector<Character*> spawnList;

	int spawnSpeed;
	float spawnTime;
};

#endif // !SPAWNER