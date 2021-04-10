#include "Background.h"
#include "GraphicHandler.h"

Background::Background()
{

	size.x = 600;
	size.y = 353;

	initialP[0] = 0;
	initialP[1] = 601;

	maxP[0] = 600;
	maxP[1] = 300;
	maxP[2] = 200;
	maxP[3] = 150;

	for (i = 0; i < 4; i++)
	{
		moveP[i] = 0;
	}
	for ( i = 0; i < 4; i++)
	{
		rect[i].top = 0 + (size.y*i);
		rect[i].left = 0;
		rect[i].right = rect[i].left + size.x;
		rect[i].bottom = rect[i].top + size.y;
	}

	D3DXCreateTextureFromFile(GraphicHandler::getInstance()->getD3dDevice(), "background.png", &texture);

	float x = 0;
	for (i = 0; i < 2; i++)
	{
		for (j = 0; j < 4; j++)
		{
			drawPosition[i][j] = { x,0,0 };
		}
		x = 601;
	}

	x = NULL;
}

Background::~Background()
{
	size = { NULL,NULL };
	initialP[0] = NULL;
	initialP[1] = NULL;

	for (i = 0; i < 4; i++)
	{
		maxP[i] = NULL;
		moveP[i] = NULL;
	}

	for ( i = 0; i < 4; i++)
	{
		rect[i] = { NULL,NULL,NULL,NULL };
	}
	texture->Release();
	texture = NULL;

	for ( i = 0; i < 2; i++)
	{
		for (j = 0; j < 4; j++)
		{
			drawPosition[i][j] = { NULL,NULL,NULL };
		}
	}

	i = NULL;
}

void Background::update()
{
	for (i = 0; i < 2; i++)
	{
		for (j = 0; j < 4; j++)
		{
			moveP[j]++;
			moveP[j] %= maxP[j];
			drawPosition[i][j].x = initialP[i] + -( j + 1) * moveP[j];
		}
	}
}

void Background::drawSprite(LPD3DXSPRITE* sprite)
{
	for ( j = 0; j < 4; j++)
	{
		for (i = 0; i < 2; i++)
		{
			(*sprite)->Draw(texture, &rect[j], NULL, &drawPosition[i][j], D3DCOLOR_XRGB(255, 255, 255));
		}
	}
}

