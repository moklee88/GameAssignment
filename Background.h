#include <d3dx9.h>
#include "GraphicHandler.h"
#include "Ginput.h"
#include "Character.h"

class Background
{
private:
	static Background* sInstance;

	LPDIRECT3DTEXTURE9 texture;
	LPDIRECT3DTEXTURE9 texture2;
	LPDIRECT3DTEXTURE9 texture3;
	LPDIRECT3DTEXTURE9 texture4;

	LPD3DXSPRITE background;

	HRESULT hr;

	RECT spriteRect, backgroundRect;

	LPDIRECT3DTEXTURE9 resource;
	int animationFrame;

	bool isCharMove = true;


public:
	Background();	
	D3DXVECTOR3 drawPosition[2][4];

	static Background* getInstance();
	static void releaseInstance();

	void update();

	RECT getRenderPosition();
	void setRenderPosition(RECT* spriteRect);

	void drawSprite();
	void release();

};