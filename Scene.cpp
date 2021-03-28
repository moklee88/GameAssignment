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

Scene::Scene()
{
	//player = new Character(3, 10, 90, 2);
}

void Scene::Scene1()
{

}