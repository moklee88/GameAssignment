#include "HealthBar.h"
#include "stdio.h"

HealthBar* HealthBar::sInstance = NULL;

HealthBar::HealthBar()
{
	this->texture = NULL;

	this->healthbar = NULL;
	this->backgroundRect = { 0,0,70,34};



	this->hr = D3DXCreateSprite(GraphicHandler::getInstance()->getD3dDevice(), &healthbar);

	this->hr = D3DXCreateTextureFromFile(GraphicHandler::getInstance()->getD3dDevice(), "HealthBar2.jpg", &texture);



	setRenderPosition(&spriteRect);
	animationFrame = 0;


	float x = 0, y = 50;
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


void HealthBar::update()
{
}

void HealthBar::drawSprite()
{
	//	Clear and begin scene

	healthbar->Begin(D3DXSPRITE_ALPHABLEND);

	//background render
	//D3DXMatrixTransformation2D(&matrix, NULL, 0.0, &scaling, NULL, 0, &characterPos);
	//sprite->SetTransform(&matrix);




	//sprite->Draw(grenade, &grenadeRect, NULL, &player->position, D3DCOLOR_XRGB(255, 255, 255));

	healthbar->Draw(texture, &backgroundRect, NULL, &drawPosition[1][0], D3DCOLOR_XRGB(255, 255, 255));
	//	Sprite rendering. Study the documentation.
	//sprite->Draw(texture, NULL, NULL, NULL, D3DCOLOR_XRGB(255, 255, 255));

	//sprite->Draw(texture, &spriteRect, NULL, &drawPosition, D3DCOLOR_XRGB(255, 255, 255));


	//	End sprite drawing
	healthbar->End();

	//	End and present scene
}



void HealthBar::release()
{
	healthbar->Release();
	healthbar = NULL;

	texture->Release();

	resource->Release();
	resource = NULL;
	texture = NULL;


	delete drawPosition;


}

HealthBar* HealthBar::getInstance() {
	if (sInstance == NULL)
		sInstance = new HealthBar();

	return sInstance;
}
void HealthBar::releaseInstance() {
	if (sInstance != NULL) {
		delete sInstance;
		sInstance = NULL;
	}
}

RECT HealthBar::getRenderPosition()
{
	return spriteRect;
}

void HealthBar::setRenderPosition(RECT* spriteRect)
{
	spriteRect->left = 0;
	spriteRect->top = 0;
	spriteRect->right = 61;
	spriteRect->bottom = 97;
}
