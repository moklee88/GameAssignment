#pragma once
#include "GraphicHandler.h"
#include "HealthBar.h"
#include <d3dx9.h>

class HealthBar
{
private:
	static HealthBar* sInstance;

	LPDIRECT3DTEXTURE9 texture;

	LPD3DXSPRITE healthbar;

	HRESULT hr;

	RECT spriteRect, backgroundRect;

	LPDIRECT3DTEXTURE9 resource;
	int animationFrame;

	bool isCharMove = true;


public:
	HealthBar();
	D3DXVECTOR3 drawPosition[2][5];

	static HealthBar* getInstance();
	static void releaseInstance();

	void update();

	RECT getRenderPosition();
	void setRenderPosition(RECT* spriteRect);

	void drawSprite();
	void release();

};
