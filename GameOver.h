#pragma once
#include "GameState.h"
#include "Font.h"
#include "Background.h"
#include <d3dx9.h>
class GameOver :public GameState
{
private:
	LPD3DXSPRITE gameOver;
	LPD3DXFONT titleFont, font;
	Font* title, * score, * scoreTitle, * retry, * mainMenu;
	int *scoreValue;
	Background* background;
public:
	GameOver();
	~GameOver();

	void init();
	void update();
	void fixUpdate();
	void draw();
	void release();
};

