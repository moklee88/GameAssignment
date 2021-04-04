#ifndef ENEMYCONTROLLER
#define ENEMYCONTROLLER

#include <vector>
#include "Character.h"
#include "Spawner.h"

class EnemyController
{
private:
	static EnemyController* sInstance;

	EnemyController(std::vector<Character*> &spawnList);
	~EnemyController();

public:
	static EnemyController* getInstance();
	static void releaseInsrance();

	void fixedUpdate();
	void update();
	void release();

	//enemy control
	LPDIRECT3DTEXTURE9 minionTexture;
	LPDIRECT3DTEXTURE9 bossTexture;

	//Spawn
	std::vector<Character*> spawnList;

};
#endif // !ENEMYCONTROLLER
