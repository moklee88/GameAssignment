#include "Scene.h"

Scene* Scene::sInstance = NULL;

Scene* Scene::getInstance() {
	if (sInstance == NULL)
		sInstance = new Scene;

	return sInstance;
}

void Scene::releaseInstance() {
	if (sInstance != NULL) {
		delete sInstance;
		sInstance = NULL;
	}
}

Character* Scene::getPlayer()
{
	return player;
}


Scene::Scene()
{
	player = new Character(3, 10, 200,-8);
}

void Scene::fixedUpdate()
{
	player->physic();
}

void Scene::Scene1()
{

	if (GInput::getInstance()->isKeyDown(DIK_W))
	{
		player->jump();

	}

	if (GInput::getInstance()->isKeyDown(DIK_A))
	{
		player->moveright();
	}
	if (GInput::getInstance()->isKeyDown(DIK_D))
	{
		player->moveleft();
	}
}