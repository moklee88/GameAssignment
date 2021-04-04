#pragma once
#include "Character.h"
#include "Ginput.h"
#include "Spawner.h"
#include "EnemyController.h"

class Scene
{
private:
	static Scene* sInstance;
	Character* player;

	RECT firstObjHitbox, secondObjHitbox;
public:
	static Scene* getInstance();
	static void releaseInstance();

	std::vector<Character*> spawnList;

	Character* getPlayer();

	Scene();

	void fixedUpdate();
	void Scene1();
	void dead();
	
	bool isPlayerCollideEnemy(D3DXVECTOR3 objPos);
	bool isPlayerCollidePlatform(D3DXVECTOR3 objPos);
	bool isCollide(D3DXVECTOR3 firstObjPos, D3DXVECTOR2 firstSize, D3DXVECTOR3 secondObjPos, D3DXVECTOR2 secondSize);
};

