#pragma once
#include "Character.h"

class Scene
{
private:
	static Scene* sInstance;

	Character* player;

public:
	static Scene* getInstance();
	static void releaseInstance();

	Scene();

	void loadScene();


};

