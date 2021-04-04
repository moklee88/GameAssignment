#pragma once
#include "GraphicHandler.h"
#include "GameMenu.h"
#include <d3dx9.h>

class GameMenu
{
private:
	static GameMenu* sInstance;

	LPDIRECT3DTEXTURE9 texture,texture2;

	LPD3DXSPRITE gamemenu;

	HRESULT hr;

	RECT spriteRect, backgroundRect;

	LPDIRECT3DTEXTURE9 resource;
	int animationFrame;




public:
	GameMenu();
	D3DXVECTOR3 drawPosition[2][5];

	static GameMenu* getInstance();
	static void releaseInstance();

	void update();

	RECT getRenderPosition();
	void setRenderPosition(RECT* spriteRect);

	void drawSprite();
	void release();

};
