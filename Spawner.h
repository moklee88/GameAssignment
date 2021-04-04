#ifndef SPAWNER
#define SPAWNER

#include <d3dx9.h>
#include <vector>

#include "Character.h"
#include "Scene.h"

class Spawner
{
private:
	static Spawner* sInstance;
	Spawner();
	~Spawner();
public:


	static Spawner* getInstance();
	static void releaseInsrance();

	void init();
	void update();

	int spawnSpeed;
	float spawnTime;
};

#endif // !SPAWNER