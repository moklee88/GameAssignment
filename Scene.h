#pragma once
#include "Character.h"
#include "Grenade.h"
#include "Ginput.h"
#include "Spawner.h"
#include "GameState.h"
#include "Background.h"

class Scene :public GameState
{
private:
	Character* player;
	Spawner* spawner;

	RECT firstObjHitbox, secondObjHitbox;

	//Sprite Variable
	LPD3DXSPRITE sprite;
	LPDIRECT3DTEXTURE9 resource;
	Grenade* grenade;
	
	Background* background;

public:
	std::vector<Character*> spawnList;
	std::vector<Character*>* ptrSpawnList;

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
	bool isCollide(D3DXVECTOR3 firstObjPos, RECT secondObjHitbox);

};

