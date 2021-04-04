#include "GameMenu.h"
#include "stdio.h"

GameMenu* GameMenu::sInstance = NULL;

GameMenu::GameMenu()
{
	this->texture = NULL;

	this->gamemenu = NULL;
	this->backgroundRect = { 0,0,125,65 };
	//this->backgroundRect = { 0,0,70,34};



	this->hr = D3DXCreateSprite(GraphicHandler::getInstance()->getD3dDevice(), &gamemenu);

	this->hr = D3DXCreateTextureFromFile(GraphicHandler::getInstance()->getD3dDevice(), "PlayButton.png", &texture);
	this->hr = D3DXCreateTextureFromFile(GraphicHandler::getInstance()->getD3dDevice(), "QuitButton.png", &texture2);



	setRenderPosition(&spriteRect);
	animationFrame = 0;



	float x = 200, y = 170;
	drawPosition[1][0] = { x,y,0 };
	x = NULL;
	y = NULL;


	float a = 200, b = 300;
	drawPosition[1][1] = { a,b,0 };
	a = NULL;
	b = NULL;

}


void GameMenu::update()
{
}

void GameMenu::drawSprite()
{
	//	Clear and begin scene

	gamemenu->Begin(D3DXSPRITE_ALPHABLEND);

	//background render
	//D3DXMatrixTransformation2D(&matrix, NULL, 0.0, &scaling, NULL, 0, &characterPos);
	//sprite->SetTransform(&matrix);




	//sprite->Draw(grenade, &grenadeRect, NULL, &player->position, D3DCOLOR_XRGB(255, 255, 255));

	gamemenu->Draw(texture, &backgroundRect, NULL, &drawPosition[1][0], D3DCOLOR_XRGB(255, 255, 255));
	gamemenu->Draw(texture2, &backgroundRect, NULL, &drawPosition[1][1], D3DCOLOR_XRGB(255, 255, 255));
	//	Sprite rendering. Study the documentation.
	//sprite->Draw(texture, NULL, NULL, NULL, D3DCOLOR_XRGB(255, 255, 255));

	//sprite->Draw(texture, &spriteRect, NULL, &drawPosition, D3DCOLOR_XRGB(255, 255, 255));


	//	End sprite drawing
	gamemenu->End();

	//	End and present scene
}



void GameMenu::release()
{
	gamemenu->Release();
	gamemenu = NULL;

	texture->Release();
	texture2->Release();

	resource->Release();
	resource = NULL;
	texture = NULL;
	texture2 = NULL;


	delete drawPosition;


}

GameMenu* GameMenu::getInstance() {
	if (sInstance == NULL)
		sInstance = new GameMenu();

	return sInstance;
}
void GameMenu::releaseInstance() {
	if (sInstance != NULL) {
		delete sInstance;
		sInstance = NULL;
	}
}

RECT GameMenu::getRenderPosition()
{
	return spriteRect;
}

void GameMenu::setRenderPosition(RECT* spriteRect)
{
	spriteRect->left = 0;
	spriteRect->top = 0;
	spriteRect->right = 61;
	spriteRect->bottom = 97;
}

