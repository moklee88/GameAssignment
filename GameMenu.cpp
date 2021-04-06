#include "GameMenu.h"
#include "Ginput.h"
#include "GraphicHandler.h"
#include "GameStateManager.h"
#include "GameWindow.h"

GameMenu::GameMenu()
{
	this->texture = NULL;

	this->gamemenu = NULL;
	this->backgroundRect = { 0,0,125,65 };

	this->hr = D3DXCreateSprite(GraphicHandler::getInstance()->getD3dDevice(), &gamemenu);

	this->hr = D3DXCreateTextureFromFile(GraphicHandler::getInstance()->getD3dDevice(), "PlayButton.png", &texture);
	this->hr = D3DXCreateTextureFromFile(GraphicHandler::getInstance()->getD3dDevice(), "QuitButton.png", &texture2);

	float x = 200, y = 170;
	drawPosition[1][0] = { x,y,0 };
	x = NULL;
	y = NULL;


	float a = 200, b = 300;
	drawPosition[1][1] = { a,b,0 };
	a = NULL;
	b = NULL;

}


void GameMenu::init()
{
}

void GameMenu::update()
{	
	GInput* input = GInput::getInstance();
	cursorPosition = D3DXVECTOR2(GameWindow::getInstance()->mouseX, GameWindow::getInstance()->mouseY);
	if (input->isMouseClick(0)) {
		if (isButtonCollide(startPosition, buttonSize)) {
			GameStateManager::getInstance()->currentState = 1;//enter select level
		}
		if (isButtonCollide(exitPosition, buttonSize)) {
			PostQuitMessage(0);
		}
	}
}

void GameMenu::fixUpdate()
{
}

void GameMenu::draw()
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


bool GameMenu::isButtonCollide(D3DXVECTOR2 position, D3DXVECTOR2 size) {
	/* D3DXVECTOR2 offset = p2 - p1;
	float l = D3DXVec2Length(&offset);
	if (l < length) {
		return true;
	}
	return false; */

		buttonRect.left = position.x;
	buttonRect.right = position.x + size.x;
	buttonRect.top = position.y;
	buttonRect.bottom = position.y + size.y;
	if (cursorPosition.y < buttonRect.top) return false;
	if (cursorPosition.x < buttonRect.left) return false;
	if (cursorPosition.x > buttonRect.right) return false;
	if (cursorPosition.y > buttonRect.bottom) return false;
	return true;
}