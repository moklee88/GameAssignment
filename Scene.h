#pragma once
#include "Character.h"
#include "Ginput.h"

class Scene
{
private:
	static Scene* sInstance;
	Character* player;

public:
	static Scene* getInstance();
	static void releaseInstance();

	
	Character* getPlayer();

	Scene();

	void fixedUpdate();
	void Scene1();
	void dead();

};

