//	Ask the compiler to include minimal header files for our program.
#define WIN32_LEAN_AND_MEAN 
#include "GameWindow.h"
#include "Ginput.h"
#include "Sprite.h"
#include <stdio.h>

//--------------------------------------------------------------------

int main() {
	GameWindow* window = GameWindow::getInstance();
	GraphicHandler* graphic = GraphicHandler::getInstance();

	GInput* input = GInput::getInstance();

	window->createWindow();

	graphic->initialize();
	
	while (window->loop())
	{


		input->update();

		Sprite::getInstance()->update();

		graphic->draw();

	}

	graphic->release();
	window->removeWindow();

	input->releaseInstance();
	window->releaseInstance();
	graphic->releaseInstance();
	Sprite::releaseInstance();

	return 0;
}