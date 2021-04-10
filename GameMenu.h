#pragma once
#include <d3dx9.h>
#include "GameState.h"
#include "Font.h"
#include "Background.h"
class GameMenu : public GameState
{
private:
	LPD3DXSPRITE gameMenu;
	LPD3DXFONT titleFont, font;
	Font *title, *enter, *esc;

	Background* background;

public:
	GameMenu();
	~GameMenu();

	void init();
	void update();
	void fixUpdate();
	void draw();
	void release();

};
