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
	player = new Character(3, 10, 200, -8, 62, 97);
	firstObjHitbox = { 0,0 };
	secondObjHitbox = { 0,0 };

}

void Scene::fixedUpdate()
{
	Spawner::getInstance()->update();

	//Movement
	player->physic();

	//Enemy activity

	for (int i = 0; i < spawnList.size(); i++)
	{
		spawnList[i]->physic();
		//check collision on player and enemy
		if (isPlayerCollideEnemy(spawnList[i]->position)||spawnList[i]->position.x <= 0)
		{
			
			if (isPlayerCollideEnemy(spawnList[i]->position))
			{
				player->lostHp();
			}
			spawnList.erase(spawnList.begin() + i);
			break;
		}


	}

	//if(grenade && (isCollide(grenade->position,21,))

}

void Scene::Scene1()
{
	//Movement
	if (GInput::getInstance()->isKeyDown(DIK_W) && player->position.y >= 300)
	{
		player->jump();
	}

	if (GInput::getInstance()->isKeyDown(DIK_A))
	{
		player->moveleft();
	}
	else if (GInput::getInstance()->isKeyDown(DIK_D))
	{
		player->moveright();
	}
	else
		player->stationary();

	//if (GInput::getInstance()->isMouseClick(DIMOFS_BUTTON1))
	//{
	//	grenade = new Grenade(&player->position);
	//}

}


bool Scene::isPlayerCollidePlatform(D3DXVECTOR3 objPos)
{
	firstObjHitbox.left = player->position.x;
	firstObjHitbox.right = player->position.x + player->size.x;
	firstObjHitbox.top = player->position.y;
	firstObjHitbox.bottom = player->position.y + player->size.y;

	secondObjHitbox.left = objPos.x;
	secondObjHitbox.right = objPos.x + 42;
	secondObjHitbox.top = objPos.y;
	secondObjHitbox.bottom = objPos.y + 11;

	firstObjHitbox.left += 21;
	firstObjHitbox.right -= 12;

	if (firstObjHitbox.bottom < secondObjHitbox.top) return false;
	if (firstObjHitbox.bottom > secondObjHitbox.bottom) return false;
	if (firstObjHitbox.right < secondObjHitbox.left) return false;
	if (firstObjHitbox.left > secondObjHitbox.right) return false;
	
	return true;
}

bool Scene::isPlayerCollideEnemy(D3DXVECTOR3 objPos)
{
	firstObjHitbox.left = player->position.x;
	firstObjHitbox.right = player->position.x + player->size.x;
	firstObjHitbox.top = player->position.y;
	firstObjHitbox.bottom = player->position.y + player->size.y;

	secondObjHitbox.left = objPos.x;
	secondObjHitbox.right = objPos.x + 42;
	secondObjHitbox.top = objPos.y;
	secondObjHitbox.bottom = objPos.y + 11;

	firstObjHitbox.left += 21;
	firstObjHitbox.right -= 12;

	secondObjHitbox.left += 21;
	secondObjHitbox.right -= 12;

	if (firstObjHitbox.bottom < secondObjHitbox.top) return false;
	if (firstObjHitbox.top > secondObjHitbox.bottom) return false;
	if (firstObjHitbox.right < secondObjHitbox.left) return false;
	if (firstObjHitbox.left > secondObjHitbox.right) return false;

	return true;
}

bool Scene::isCollide(D3DXVECTOR3 firstObjPos, D3DXVECTOR2 firstSize, D3DXVECTOR3 secondObjPos, D3DXVECTOR2 secondSize)
{
	firstObjHitbox.left = firstObjPos.x;
	firstObjHitbox.right = firstObjPos.x + firstSize.x;
	firstObjHitbox.top = firstObjPos.y;
	firstObjHitbox.bottom = firstObjPos.y + firstSize.y;

	secondObjHitbox.left = secondObjPos.x;
	secondObjHitbox.right = secondObjPos.x + secondSize.x;
	secondObjHitbox.top = secondObjPos.y;
	secondObjHitbox.bottom = secondObjPos.y + secondSize.y;

	if (firstObjHitbox.bottom < secondObjHitbox.top) return false;
	if (firstObjHitbox.top > secondObjHitbox.bottom) return false;
	if (firstObjHitbox.right < secondObjHitbox.left) return false;
	if (firstObjHitbox.left > secondObjHitbox.right) return false;

	return true;
}


