#pragma once
#include "Character.h"
#include "Grenade.h"
#include "Ginput.h"
#include "Spawner.h"
#include "GameState.h"

class Scene :public GameState
{
private:
	static Scene* sInstance;
	Character* player;

	RECT firstObjHitbox, secondObjHitbox;

	//Sprite Variable
	LPD3DXSPRITE sprite;
	LPDIRECT3DTEXTURE9 resource;

public:
	static Scene* getInstance();
	static void releaseInstance();

	std::vector<Character*> spawnList;
	Grenade* grenade;

	Character* getPlayer();

	Scene();
	~Scene();
	
	void init();
	void update();
	void fixUpdate();
	void draw();
	void release();
	
	bool isPlayerCollideEnemy(D3DXVECTOR3 objPos);
	bool isPlayerCollidePlatform(D3DXVECTOR3 objPos);
	bool isCollide(D3DXVECTOR3 firstObjPos, D3DXVECTOR2 firstSize, D3DXVECTOR3 secondObjPos, D3DXVECTOR2 secondSize);
};

