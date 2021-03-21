#include "Sprite.h"

Sprite* Sprite::sInstance = NULL;

Sprite::Sprite()
{
	this->texture = NULL;
	this->texture2 = NULL;
	this->texture3 = NULL;
	this->texture4 = NULL;

	this->sprite = NULL;
	this->backgroundRect = { 0,0,400,400 };
	setRenderPosition();

	this->hr = D3DXCreateSprite(GraphicHandler::getInstance()->getD3dDevice(), &sprite);

	this->hr = D3DXCreateTextureFromFile(GraphicHandler::getInstance()->getD3dDevice(), "backtree.png", &texture);
	this->hr = D3DXCreateTextureFromFile(GraphicHandler::getInstance()->getD3dDevice(), "tree.png", &texture2);
	this->hr = D3DXCreateTextureFromFile(GraphicHandler::getInstance()->getD3dDevice(), "middletree.png", &texture3);
	this->hr = D3DXCreateTextureFromFile(GraphicHandler::getInstance()->getD3dDevice(), "light.png", &texture4);


	int x = 0;
	for (int r = 0; r < 2; r++)
	{

		for (int c = 0; c < 4; c++)
		{
			drawPosition[r][c] = { x,0,0 };
		}

		x = 1080;
	}

}


Sprite* Sprite::getInstance() {
	if (sInstance == NULL)
		sInstance = new Sprite();

	return sInstance;
}
void Sprite::releaseInstance() {
	if (sInstance != NULL) {
		delete sInstance;
		sInstance = NULL;
	}
}

RECT Sprite::getRenderPosition()
{
	return spriteRect;
}

void Sprite::setRenderPosition()
{
	this->spriteRect.left = 0;
	this->spriteRect.top = 0;
	this->spriteRect.right = 57;
	this->spriteRect.bottom = 96;
}


void Sprite::update()
{
	if (GInput::getInstance()->isKeyDown(DIK_RIGHT))
	{
		isCharMove = true;

		for (int x = 0; x < 2; x++)
		{
			for (int y = 0; y < 4; y++)
			{
				drawPosition[x][y].x -= y + 1;
			}
		}
	}
}

void Sprite::drawSprite()
{
	//	Clear and begin scene

	sprite->Begin(D3DXSPRITE_ALPHABLEND);

	//background render
	//D3DXMatrixTransformation2D(&matrix, NULL, 0.0, &scaling, NULL, 0, &characterPos);
	//sprite->SetTransform(&matrix);
	//for (int i = 0; i < array.size; i++)
	

	sprite->Draw(texture, &backgroundRect, NULL, &drawPosition[0][0], D3DCOLOR_XRGB(255, 255, 255));
	sprite->Draw(texture4, &backgroundRect, NULL, &drawPosition[0][1], D3DCOLOR_XRGB(255, 255, 255));
	sprite->Draw(texture3, &backgroundRect, NULL, &drawPosition[0][2], D3DCOLOR_XRGB(255, 255, 255));
	sprite->Draw(texture2, &backgroundRect, NULL, &drawPosition[0][3], D3DCOLOR_XRGB(255, 255, 255));

	sprite->Draw(texture, &backgroundRect, NULL, &drawPosition[1][0], D3DCOLOR_XRGB(255, 255, 255));
	sprite->Draw(texture4, &backgroundRect, NULL, &drawPosition[1][1], D3DCOLOR_XRGB(255, 255, 255));
	sprite->Draw(texture3, &backgroundRect, NULL, &drawPosition[1][2], D3DCOLOR_XRGB(255, 255, 255));
	sprite->Draw(texture2, &backgroundRect, NULL, &drawPosition[1][3], D3DCOLOR_XRGB(255, 255, 255));

	//	Sprite rendering. Study the documentation.
	//sprite->Draw(texture, NULL, NULL, NULL, D3DCOLOR_XRGB(255, 255, 255));

	//sprite->Draw(texture, &spriteRect, NULL, &drawPosition, D3DCOLOR_XRGB(255, 255, 255));


	//	End sprite drawing
	sprite->End();

	//	End and present scene
}

void Sprite::release()
{
	sprite->Release();
	sprite = NULL;

	texture->Release();
	texture2->Release();
	texture3->Release();
	texture4->Release();
	texture = NULL;
	texture2 = NULL;
	texture3 = NULL;
	texture4 = NULL;

	delete drawPosition;

	
}