#include <d3dx9.h>
#include "GraphicHandler.h"
#include "Ginput.h"
class Sprite
{
private:
	static Sprite* sInstance;

	LPDIRECT3DTEXTURE9 texture;
	LPDIRECT3DTEXTURE9 texture2;
	LPDIRECT3DTEXTURE9 texture3;
	LPDIRECT3DTEXTURE9 texture4;

	LPDIRECT3DTEXTURE9 player;

	LPD3DXSPRITE sprite;

	HRESULT hr;

	RECT spriteRect, backgroundRect;

	D3DXVECTOR2 characterSize;
	D3DXVECTOR3 characterPosition;

	int animationFrame;

	bool isCharMove = true;


public:
	Sprite();
	D3DXVECTOR3 drawPosition[2][4];

	static Sprite* getInstance();
	static void releaseInstance();

	void update();

	RECT getRenderPosition();
	void setRenderPosition(RECT* spriteRect);

	void drawSprite();
	void release();

};