#include "GameOver.h"
#include "Ginput.h"
#include "GraphicHandler.h"
#include "GameStateManager.h"
#include "GameWindow.h"
#include "Score.h"

GameOver::GameOver()
{
	this->gameOver = NULL;

	D3DXCreateSprite(GraphicHandler::getInstance()->getD3dDevice(), &gameOver);

	title = new Font("GameOver", 160, 120, 300, 110);
	scoreTitle = new Font("Your Score is", 100, 400, 200, 50);
	score = new Font(0, 300, 400, 200, 50);
	retry = new Font("Press ""R"" to Restart", 100, 450, 200, 50);
	mainMenu = new  Font("Press ""M"" to return Main Menu", 100, 500, 200, 50);

	background = new Background();

	D3DXCreateFont(GraphicHandler::getInstance()->getD3dDevice(), 70, 0, 0, 1, false,
		DEFAULT_CHARSET, OUT_TT_ONLY_PRECIS, DEFAULT_QUALITY,
		DEFAULT_PITCH | FF_DONTCARE, "Segoe Script", &titleFont);

	D3DXCreateFont(GraphicHandler::getInstance()->getD3dDevice(), 30, 0, 0, 1, false,
		DEFAULT_CHARSET, OUT_TT_ONLY_PRECIS, DEFAULT_QUALITY,
		DEFAULT_PITCH | FF_DONTCARE, "Segoe Script", &font);
}
GameOver::~GameOver()
{
	release();
}

void GameOver::init()
{
}

void GameOver::update()
{
	background->update();
	if (GInput::getInstance()->isKeyDown(DIK_RETURN))
	{
		GameStateManager::getInstance()->currentState = 1;
	}
	if (GInput::getInstance()->isKeyDown(DIK_M))
	{
		GameStateManager::getInstance()->currentState = 0;
	}
}

void GameOver::fixUpdate()
{
}

void GameOver::draw()
{
	gameOver->Begin(D3DXSPRITE_ALPHABLEND);

	background->drawSprite(&gameOver);
	titleFont->DrawText(gameOver, title->word, -1, &title->position, DT_LEFT, D3DCOLOR_XRGB(0, 0, 0));
	font->DrawText(gameOver, scoreTitle->word, -1, &scoreTitle->position, DT_LEFT, D3DCOLOR_XRGB(254, 254, 254));
	font->DrawText(gameOver, std::to_string(Score::getInstance()->getValue()).c_str(), -1, &score->position, DT_LEFT, D3DCOLOR_XRGB(254, 254, 254));
	font->DrawText(gameOver, retry->word, -1, &retry->position, DT_LEFT, D3DCOLOR_XRGB(254, 254, 254));
	font->DrawText(gameOver, mainMenu->word, -1, &mainMenu->position, DT_LEFT, D3DCOLOR_XRGB(254, 254, 254));

	gameOver->End();
}


void GameOver::release()
{
	gameOver->Release();
	gameOver = NULL;

	delete title;
	title = NULL;

	delete score;
	score = NULL;

	delete background;
	background = NULL;

	font->Release();
	font = NULL;
}



