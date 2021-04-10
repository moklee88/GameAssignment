#include "GameMenu.h"
#include "Ginput.h"
#include "GraphicHandler.h"
#include "GameStateManager.h"
#include "GameWindow.h"]
#include "Sound.h"

GameMenu::GameMenu()
{
	this->gameMenu = NULL;

	D3DXCreateSprite(GraphicHandler::getInstance()->getD3dDevice(), &gameMenu);

	title = new Font("MadRun", 160, 120, 200, 110);
	enter = new Font("Press Enter to Play", 150, 170, 250, 30);
	esc = new Font("Press ESC to Exit", 160, 200, 200, 30);

	background = new Background();

	D3DXCreateFont(GraphicHandler::getInstance()->getD3dDevice(), 50, 0, 0, 1, false,
		DEFAULT_CHARSET, OUT_TT_ONLY_PRECIS, DEFAULT_QUALITY,
		DEFAULT_PITCH | FF_DONTCARE, "Segoe Script", &titleFont);

	D3DXCreateFont(GraphicHandler::getInstance()->getD3dDevice(), 35, 0, 0, 1, false,
		DEFAULT_CHARSET, OUT_TT_ONLY_PRECIS, DEFAULT_QUALITY,
		DEFAULT_PITCH | FF_DONTCARE, "Segoe Script", &font);

	Sound::getInstance()->playBgmSound();
}
GameMenu::~GameMenu()
{
	release();
}

void GameMenu::init()
{
}

void GameMenu::update()
{	
	background->update();
	if (GInput::getInstance()->isKeyDown(DIK_RETURN))
	{
		GameStateManager::getInstance()->currentState = 1;
	}
}

void GameMenu::fixUpdate()
{
}

void GameMenu::draw()
{
	gameMenu->Begin(D3DXSPRITE_ALPHABLEND);

	background->drawSprite(&gameMenu);

	titleFont->DrawText(gameMenu, title->word, -1, &title->position, DT_LEFT, D3DCOLOR_XRGB(0, 0, 0));
	font->DrawText(gameMenu, enter->word, -1, &enter->position, DT_LEFT, D3DCOLOR_XRGB(0, 0, 0));
	font->DrawText(gameMenu, esc->word, -1, &esc->position, DT_LEFT, D3DCOLOR_XRGB(0, 0, 0));

	gameMenu->End();
}


void GameMenu::release()
{
	gameMenu->Release();
	gameMenu = NULL;

	delete title;
	title = NULL;

	delete enter;
	enter = NULL;

	delete esc;
	esc = NULL;

	delete background;
	background = NULL;

	font->Release();
	font = NULL;

}


