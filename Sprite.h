#include <d3dx9.h>
#include "GraphicHandler.h"
class Sprite
{
private:
	static Sprite* sInstance;

	LPDIRECT3DTEXTURE9 texture;
	LPDIRECT3DTEXTURE9 texture2;
	LPDIRECT3DTEXTURE9 texture3;
	LPDIRECT3DTEXTURE9 texture4;

	LPD3DXSPRITE sprite;

	HRESULT hr;

	RECT spriteRect, backgroundRect;

public:
	Sprite();
	D3DXVECTOR3 drawPosition;

	static Sprite* getInstance();
	static void releaseInstance();

	RECT getRenderPosition();
	void setRenderPosition();

	void drawSprite();
	void release();

};