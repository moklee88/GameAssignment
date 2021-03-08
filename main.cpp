//	Ask the compiler to include minimal header files for our program.
#define WIN32_LEAN_AND_MEAN
#include "GameWindow.h"
#include <stdio.h>

//--------------------------------------------------------------------

int main() {
	GameWindow* window = GameWindow::getInstance();
	GraphicHandler* graphic = GraphicHandler::getInstance();

	window->createWindow();

	graphic->initialize();
	graphic->draw();

	while (window->loop())
	{
		printf("Finally succeed\n");

	}

	graphic->clear();
	window->removeWindow();

	window->releaseInstance();
	graphic->releaseInstance();

	return 0;
}