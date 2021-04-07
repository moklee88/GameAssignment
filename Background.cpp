#include "Background.h"
#include "GraphicHandler.h"

Background::Background()
{

	backgroundRect = { 0,0,400,250 };
	backgroundRect2 = { 0,0,500,250 };

	D3DXCreateTextureFromFile(GraphicHandler::getInstance()->getD3dDevice(), "backtree.png", &texture);
	D3DXCreateTextureFromFile(GraphicHandler::getInstance()->getD3dDevice(), "tree.png", &texture2);
	D3DXCreateTextureFromFile(GraphicHandler::getInstance()->getD3dDevice(), "middletree.png", &texture3);
	D3DXCreateTextureFromFile(GraphicHandler::getInstance()->getD3dDevice(), "light.png", &texture4);



	for (int r = 0; r < 2; r++)
	{
		for (int c = 0; c < 4; c++)
		{
			drawPosition[r][c] = { 0,100,0 };
		}
	}

	maxFrame[0] = 500;
	maxFrame[1] = 272;
	maxFrame[2] = 150;
	maxFrame[3] = 100;
	for (int i = 0; i < 4; i++)
	{
		frame[i] = 0;
	}

}

Background::~Background()
{
	backgroundLoader = NULL;

	texture->Release();
	texture2->Release();
	texture3->Release();
	texture4->Release();

	texture = NULL;
	texture2 = NULL;
	texture3 = NULL;
	texture4 = NULL;

	for (int x = 0; x < 2; x++)
	{
		for (int y = 0; y < 4; y++)
		{
			drawPosition[x][y] = { NULL,NULL,NULL };
		}
	}

	for (int i = 0; i < 4; i++)
	{
		frame[i] = NULL;
	}

	maxFrame[0] = NULL;
	maxFrame[1] = NULL;
	maxFrame[2] = NULL;
	maxFrame[3] = NULL;

	backgroundRect = { NULL,NULL,NULL,NULL };
	backgroundRect2 = { NULL,NULL,NULL,NULL };
}

void Background::update()
{
	for (int x = 0; x < 2; x++)
	{
		for (int y = 0; y < 4; y++)
		{
			frame[y]++;
			frame[y] %= maxFrame[y];
			drawPosition[x][y].x = (-y-1) * frame[y];
		}
	}
}

void Background::drawSprite(LPD3DXSPRITE* sprite)
{
	//	Clear and begin scene

	//background render
	//D3DXMatrixTransformation2D(&matrix, NULL, 0.0, &scaling, NULL, 0, &characterPos);
	//sprite->SetTransform(&matrix);

	//(*sprite)->Draw(texture, &backgroundRect2, NULL, &drawPosition[1][0], D3DCOLOR_XRGB(255, 255, 255));
	//(*sprite)->Draw(texture4, &backgroundRect, NULL, &drawPosition[1][1], D3DCOLOR_XRGB(255, 255, 255));
	//(*sprite)->Draw(texture3, &backgroundRect, NULL, &drawPosition[1][2], D3DCOLOR_XRGB(255, 255, 255));
	//(*sprite)->Draw(texture2, &backgroundRect, NULL, &drawPosition[1][3], D3DCOLOR_XRGB(255, 255, 255));

	//	End sprite drawing
	//	End and present scene
}

