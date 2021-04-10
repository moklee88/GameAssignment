#pragma once
#include "Character.h"
#include "Grenade.h"
#include "Bullet.h"
#include "Ginput.h"
#include "Spawner.h"
#include "Object.h"
#include "Gun.h"
#include "GameState.h"
#include "Background.h"
#include "UI.h"


class Scene :public GameState
{
private:
	int score;

	Character* player;
	Spawner* spawner;
	Bullet* bullet;
	Gun* gun;

	bool isJump;
	D3DXVECTOR3 mousePosition, mouseCenter,gunActual;

	RECT firstObjHitbox, secondObjHitbox, mouse;

	//Sprite Variable
	LPD3DXSPRITE sprite;
	LPDIRECT3DTEXTURE9 resource;
	Grenade* grenade;
	
	Background* background;
	UI* gUI;

public:
	std::vector<Character*> spawnList;
	std::vector<Character*>* ptrSpawnList;

	std::vector<Platform*> platformList;
	std::vector<Platform*>* ptrPlatformList;

	std::vector<Coins*> coinList;
	std::vector<Coins*>* ptrCoinList;

	Scene();
	~Scene();
	
	void init();
	void update();
	void fixUpdate();
	void draw();
	void release();

	int getScore();
	bool isPlayerCollideEnemy(D3DXVECTOR3 objPos);
	bool isPlayerCollidePlatform(D3DXVECTOR3 objPos, D3DXVECTOR2 size);
	bool isCollide(D3DXVECTOR3 firstObjPos, D3DXVECTOR2 firstSize, D3DXVECTOR3 secondObjPos, D3DXVECTOR2 secondSize);
	bool isCollide(D3DXVECTOR3 firstObjPos, D3DXVECTOR3 secondObj, int size);

};

