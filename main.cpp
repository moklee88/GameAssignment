//	Ask the compiler to include minimal header files for our program.
#define WIN32_LEAN_AND_MEAN 
#include "GameWindow.h"
#include "Ginput.h"
#include "GameStateManager.h"
#include <stdio.h>

//--------------------------------------------------------------------

int main() {
	GameWindow* window = GameWindow::getInstance();
	GraphicHandler* graphic = GraphicHandler::getInstance();

	GInput* input = GInput::getInstance();

	window->createWindow();

	graphic->initialize();
	GameStateManager* state = GameStateManager::getInstance();

	while (window->loop())
	{
		input->update();
		state->update();

		graphic->draw();
	}

	graphic->release();
	window->removeWindow();

	input->releaseInstance();
	window->releaseInstance();
	graphic->releaseInstance();

	state->releaseInstance();


	return 0;
}