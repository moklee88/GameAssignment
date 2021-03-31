//	Ask the compiler to include minimal header files for our program.
#define WIN32_LEAN_AND_MEAN 
#include "GameWindow.h"
#include "Ginput.h"
#include "Background.h"
#include "Sprite.h"
#include "FrameTimer.h"
#include "Scene.h"
#include <stdio.h>

//--------------------------------------------------------------------

int main() {
	GameWindow* window = GameWindow::getInstance();
	GraphicHandler* graphic = GraphicHandler::getInstance();

	FrameTimer* timer = new FrameTimer();

	GInput* input = GInput::getInstance();

	timer->init(18);

	window->createWindow();

	graphic->initialize();
	
	while (window->loop())
	{

		input->update();
		Scene::getInstance()->fixedUpdate();
		Scene::getInstance()->Scene1();

		int frameToUpdate = timer->framesToUpdate();
		for (int i = 0; i < frameToUpdate; i++)
		{
		
			Background::getInstance()->update();
			Sprite::getInstance()->update();
		}
		graphic->draw();

	}

	graphic->release();
	window->removeWindow();

	input->releaseInstance();
	window->releaseInstance();
	graphic->releaseInstance();
	Sprite::releaseInstance();
	Background::releaseInstance();
	

	delete timer;

	return 0;
}