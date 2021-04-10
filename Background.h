#pragma once
#include <d3dx9.h>

class Background
{
private:
	LPDIRECT3DTEXTURE9 texture;

	int i, j;
	RECT rect[4];
	D3DXVECTOR2 size;

	D3DXVECTOR3 drawPosition[2][4];
	int initialP[2], maxP[4], moveP[4];


public:
	Background();
	~Background();

	void update();

	void drawSprite(LPD3DXSPRITE* sprite);

};