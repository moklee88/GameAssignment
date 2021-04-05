//	Ask the compiler to include minimal header files for our program.
#define WIN32_LEAN_AND_MEAN 
#include "GameWindow.h"
#include "Ginput.h"
#include "Background.h"
#include "GameStateManager.h"
#include "HealthBar.h"
#include "FrameTimer.h"
#include "Scene.h"
#include <stdio.h>

//--------------------------------------------------------------------

int main() {
	GameWindow* window = GameWindow::getInstance();
	GraphicHandler* graphic = GraphicHandler::getInstance();

	GInput* input = GInput::getInstance();
	GameStateManager* state = GameStateManager::getInstance();

	window->createWindow();

	graphic->initialize();
	
	while (window->loop())
	{

		input->update();
		state->update();
		//Scene::getInstance()->fixedUpdate();
		//Scene::getInstance()->Scene1();

		//Background::getInstance()->update();
		//Sprite::getInstance()->update();

		graphic->draw();
	}

	graphic->release();
	window->removeWindow();

	input->releaseInstance();
	window->releaseInstance();
	graphic->releaseInstance();

	state->releaseInstance();
	//Sprite::releaseInstance();
	//Background::releaseInstance();
	//HealthBar::releaseInstance();
	//Scene::releaseInstance();

	return 0;
}