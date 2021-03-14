//	Ask the compiler to include minimal header files for our program.
#define WIN32_LEAN_AND_MEAN 
#include "GameWindow.h"
#include "Sprite.h"
#include <stdio.h>

//--------------------------------------------------------------------

int main() {
	GameWindow* window = GameWindow::getInstance();
	GraphicHandler* graphic = GraphicHandler::getInstance();

	

	window->createWindow();

	graphic->initialize();
	
	while (window->loop())
	{
		graphic->draw();


	}

	graphic->release();
	window->removeWindow();

	window->releaseInstance();
	graphic->releaseInstance();
	Sprite::releaseInstance();

	return 0;
}