#include <d3dx9.h>
#include "GraphicHandler.h"
#include "Ginput.h"
#include "Character.h"
#include "Scene.h"

class Sprite
{
private:
	static Sprite* sInstance;

	LPDIRECT3DTEXTURE9 resource;
	LPDIRECT3DTEXTURE9 grenade;

	LPD3DXSPRITE sprite;

	HRESULT hr;

	RECT playerRect, backgroundRect,grenadeRect,enemyRect;

	D3DXVECTOR2 playerSize;

	int animationFrame;

public:
	Sprite();

	static Sprite* getInstance();
	static void releaseInstance();

	void update();

	RECT getRenderPosition();

	void drawSprite(Character* player, std::vector<Character*>& spawnList);
	void release();

};