#pragma once
#include <d3dx9.h>
#include "GameState.h"
class GameMenu : public GameState
{
private:
	LPDIRECT3DTEXTURE9 texture,texture2;

	LPD3DXSPRITE gamemenu;

	HRESULT hr;

	RECT spriteRect, backgroundRect;

	LPDIRECT3DTEXTURE9 resource;
	int animationFrame;

	LPDIRECT3DTEXTURE9 menu = NULL, startbutton = NULL, exitbutton = NULL, cursorTexture = NULL;
	LPD3DXSPRITE sprite = NULL;
	RECT buttonRect;
	D3DXMATRIX menumat, startmat, exitmat, cursormat;
	D3DXVECTOR2 buttonSize;
	D3DXVECTOR2 menuPosition, startPosition, exitPosition, cursorPosition;

public:


	GameMenu();
	~GameMenu();
	D3DXVECTOR3 drawPosition[2][5];


	void init();
	void update();
	void fixUpdate();
	void draw();
	void release();



	bool isButtonCollide(D3DXVECTOR2 position, D3DXVECTOR2 size);
};
