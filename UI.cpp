#include "UI.h"
#include "GraphicHandler.h"
#include <string>

UI::UI()
{
	i = 0;

	hpRect.top = 228;
	hpRect.left = 0;
	hpRect.right = 26;
	hpRect.bottom = 250;

	//rectScoreStr.top = 410;
	//rectScoreStr.left = 10;
	//rectScoreStr.right = 70;
	//rectScoreStr.bottom = 300;

	scoreStr = new Font("Score: ", 10, 410, 110, 60);

	rectScore.top = scoreStr->position.top;
	rectScore.left = scoreStr->position.right + 30;
	rectScore.right = rectScore.left + 60;
	rectScore.bottom = scoreStr->position.bottom;

	D3DXCreateFont(GraphicHandler::getInstance()->getD3dDevice(), 35, 0, 0, 1, false,
		DEFAULT_CHARSET, OUT_TT_ONLY_PRECIS, DEFAULT_QUALITY,
		DEFAULT_PITCH | FF_DONTCARE, "Segoe Script", &scoreFont);


	hpPosition[0] = { 10,370,0 };
	hpPosition[1] = { 50,370,0 };
	hpPosition[2] = { 90,370,0 };

}

UI::~UI()
{
	scoreFont->Release();
	scoreFont = NULL;

	hpRect.top = NULL;
	hpRect.left = NULL;
	hpRect.right = NULL;
	hpRect.bottom = NULL;

	delete scoreStr;
	scoreStr = NULL;

	rectScore.top = NULL;
	rectScore.left = NULL;
	rectScore.right = NULL;
	rectScore.bottom = NULL;
}


void UI::drawSprite(LPD3DXSPRITE* sprite, LPDIRECT3DTEXTURE9* resource, int hp, int score)
{
	for (i = 0; i < hp; i++)
	{
		(*sprite)->Draw(*resource, &hpRect, NULL, &hpPosition[i], D3DCOLOR_XRGB(255, 255, 255));
	}

	scoreFont->DrawText(*sprite, std::to_string(score).c_str(), -1, &rectScore, DT_LEFT, D3DCOLOR_XRGB(254, 254, 254));

	scoreFont->DrawText(*sprite, scoreStr->word, -1, &scoreStr->position, DT_LEFT, D3DCOLOR_XRGB(254, 254, 254));

}