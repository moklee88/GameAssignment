#pragma once
#include <d3dx9.h>
#include "Font.h"

using namespace std;
class UI
{
private:
	RECT hpRect,rectScore;
	D3DXVECTOR3 hpPosition[3];
	LPD3DXFONT scoreFont;

	Font* scoreStr;

	int i;
public:
	UI();
	~UI();

	void drawSprite(LPD3DXSPRITE* sprite, LPDIRECT3DTEXTURE9* resource, int hp, int *score);
};

