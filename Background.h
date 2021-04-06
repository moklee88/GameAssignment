#pragma once
#include <d3dx9.h>

class Background
{
private:
	LPDIRECT3DTEXTURE9 texture;
	LPDIRECT3DTEXTURE9 texture2;
	LPDIRECT3DTEXTURE9 texture3;
	LPDIRECT3DTEXTURE9 texture4;

	LPD3DXSPRITE **backgroundLoader;

	RECT backgroundRect, backgroundRect2;

	int frame[4], maxFrame[4];
public:
	D3DXVECTOR3 drawPosition[2][5];

	Background();
	~Background();
	

	void update();

	void drawSprite(LPD3DXSPRITE* sprite);

};