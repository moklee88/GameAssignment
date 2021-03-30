#include "Background.h"
#include "stdio.h"

Background* Background::sInstance = NULL;

Background::Background()
{
	this->texture = NULL;
	this->texture2 = NULL;
	this->texture3 = NULL;
	this->texture4 = NULL;

	this->background = NULL;
	this->backgroundRect = { 0,0,400,250 };
	this->backgroundRect2 = { 0,0,500,250 };



	this->hr = D3DXCreateSprite(GraphicHandler::getInstance()->getD3dDevice(), &background);

	this->hr = D3DXCreateTextureFromFile(GraphicHandler::getInstance()->getD3dDevice(), "backtree.png", &texture);
	this->hr = D3DXCreateTextureFromFile(GraphicHandler::getInstance()->getD3dDevice(), "tree.png", &texture2);
	this->hr = D3DXCreateTextureFromFile(GraphicHandler::getInstance()->getD3dDevice(), "middletree.png", &texture3);
	this->hr = D3DXCreateTextureFromFile(GraphicHandler::getInstance()->getD3dDevice(), "light.png", &texture4);

	

	setRenderPosition(&spriteRect);
	animationFrame = 0;


	float x = 0, y=100;
	for (int r = 0; r < 2; r++)
	{

		for (int c = 0; c < 4; c++)
		{
			drawPosition[r][c] = { x,y,0 };
		}

		x = 0;
	}
	x = NULL;
	y = NULL;

}


void Background::update()
{

	isCharMove = true;

	for (int x = 0; x < 2; x++)
	{
		for (int y = 0; y < 4; y++)
		{
			drawPosition[x][y].x -= y + 0.5;
		}
	}

	/*if (GInput::getInstance()->isKeyDown(DIK_D))
	{
		isCharMove = true;

		for (int x = 0; x < 2; x++)
		{
			for (int y = 0; y < 4; y++)
			{
				drawPosition[x][y].x -= y + 1;
			}
		}
	}*/
}

void Background::drawSprite()
{
	//	Clear and begin scene

	background->Begin(D3DXSPRITE_ALPHABLEND);

	//background render
	//D3DXMatrixTransformation2D(&matrix, NULL, 0.0, &scaling, NULL, 0, &characterPos);
	//sprite->SetTransform(&matrix);



	//sprite->Draw(texture, &backgroundRect, NULL, &drawPosition[0][0], D3DCOLOR_XRGB(255, 255, 255));
	//sprite->Draw(texture4, &backgroundRect, NULL, &drawPosition[0][1], D3DCOLOR_XRGB(255, 255, 255));
	//sprite->Draw(texture3, &backgroundRect, NULL, &drawPosition[0][2], D3DCOLOR_XRGB(255, 255, 255));
	//sprite->Draw(texture2, &backgroundRect, NULL, &drawPosition[0][3], D3DCOLOR_XRGB(255, 255, 255));


	//sprite->Draw(grenade, &grenadeRect, NULL, &player->position, D3DCOLOR_XRGB(255, 255, 255));

	background->Draw(texture, &backgroundRect2, NULL, &drawPosition[1][0], D3DCOLOR_XRGB(255, 255, 255));
	background->Draw(texture4, &backgroundRect, NULL, &drawPosition[1][1], D3DCOLOR_XRGB(255, 255, 255));
	background->Draw(texture3, &backgroundRect, NULL, &drawPosition[1][2], D3DCOLOR_XRGB(255, 255, 255));
	background->Draw(texture2, &backgroundRect, NULL, &drawPosition[1][3], D3DCOLOR_XRGB(255, 255, 255));

	//	Sprite rendering. Study the documentation.
	//sprite->Draw(texture, NULL, NULL, NULL, D3DCOLOR_XRGB(255, 255, 255));

	//sprite->Draw(texture, &spriteRect, NULL, &drawPosition, D3DCOLOR_XRGB(255, 255, 255));


	//	End sprite drawing
	background->End();

	//	End and present scene
}



void Background::release()
{
	background->Release();
	background = NULL;

	texture->Release();
	texture2->Release();
	texture3->Release();
	texture4->Release();
	resource->Release();
	resource = NULL;
	texture = NULL;
	texture2 = NULL;
	texture3 = NULL;
	texture4 = NULL;

	delete drawPosition;


}

Background* Background::getInstance() {
	if (sInstance == NULL)
		sInstance = new Background();

	return sInstance;
}
void Background::releaseInstance() {
	if (sInstance != NULL) {
		delete sInstance;
		sInstance = NULL;
	}
}

RECT Background::getRenderPosition()
{
	return spriteRect;
}

void Background::setRenderPosition(RECT* spriteRect)
{
	spriteRect->left = 0;
	spriteRect->top = 0;
	spriteRect->right = 61;
	spriteRect->bottom = 97;
}
