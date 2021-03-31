#include <d3dx9.h>
#include "GraphicHandler.h"
#include "Ginput.h"
#include "Character.h"

class Sprite
{
private:
	static Sprite* sInstance;

	LPDIRECT3DTEXTURE9 resource;
	LPDIRECT3DTEXTURE9 grenade;

	LPD3DXSPRITE sprite;

	HRESULT hr;

	RECT spriteRect, backgroundRect,grenadeRect;

	D3DXVECTOR2 characterSize;

	int animationFrame;

public:
	Sprite();

	static Sprite* getInstance();
	static void releaseInstance();

	void update();

	RECT getRenderPosition();
	void setRenderPosition(RECT* spriteRect);

	void drawSprite(Character* player);
	void release();

};