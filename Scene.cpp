#include "Scene.h"
#include "GraphicHandler.h"
#include "Sound.h"
#include "GameStateManager.h"
#include "Score.h"

Scene::Scene()
{
	score = 0;

	gunActual = { 0,0,0 };
	grenade = NULL;
	player = new Character(3, 10, 200);
	firstObjHitbox = { 0,0,0,0 };
	secondObjHitbox = { 0,0,0,0 };

	gun = new Gun(&player->position,40,22,645,11);

	mousePosition = { 0,0,0 };
	mouseCenter = { 26,26,0 };

	mouse = { 593,11,645,63 };

	isJump = true;

	ptrSpawnList = &spawnList;
	ptrPlatformList = &platformList;
	ptrCoinList = &coinList;


	spawner = new Spawner(ptrSpawnList, ptrPlatformList, ptrCoinList);

	D3DXCreateSprite(GraphicHandler::getInstance()->getD3dDevice(), &sprite);

	bullet = NULL;
	background = new Background();
	gUI = new UI();

	D3DXCreateTextureFromFile(GraphicHandler::getInstance()->getD3dDevice(), "resources.png", &resource);
}

Scene::~Scene()
{
	release();
}

void Scene::release()
{
	//Sprite Release
	sprite->Release();
	sprite = NULL;

	resource->Release();
	resource = NULL;

	delete player;
	player = NULL;

	delete bullet;
	bullet = NULL;

	delete grenade;
	grenade = NULL;

	firstObjHitbox = { NULL,NULL,NULL,NULL };
	secondObjHitbox = { NULL,NULL,NULL,NULL };

	mousePosition = { NULL,NULL,NULL };
	mouseCenter = { NULL,NULL,NULL };

	mouse = { NULL,NULL,NULL,NULL };

	isJump = NULL;

	ptrSpawnList = NULL;
	ptrPlatformList = NULL;
	ptrCoinList = NULL;

	delete spawner;
	spawner = NULL;

	delete background;
	background = NULL;

	delete gUI;
	gUI = NULL;

	for (int i = 0; i < spawnList.size(); i++)
	{
		delete spawnList[i];
		spawnList[i] = NULL;
	}
	for (int i = 0; i < platformList.size(); i++)
	{
		delete platformList[i];
		platformList[i] = NULL;
	}
	for (int i = 0; i < coinList.size(); i++)
	{
		delete coinList[i];
		coinList[i] = NULL;
	}

	score = NULL;
}

void Scene::init()
{

}

void Scene::fixUpdate()
{

	background->update();
	player->animation();

	for (int i = 0; i < spawnList.size(); i++)
	{
		spawnList[i]->animation();
	}

	for (int i = 0; i < coinList.size(); i++)
	{
		coinList[i]->animation();
	}
}

void Scene::update()
{
	//Mouse
	mousePosition = GInput::getInstance()->getMousePosition() - (26, 26, 0);

	//Movement
	if (GInput::getInstance()->isKeyDown(DIK_W) && (player->position.y >= player->getBoundary() || isJump == true))
	{
		player->jump();
		isJump = false;
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

	//Launch Grenade
	if (GInput::getInstance()->isMouseClick(1) && grenade == NULL)
	{
		grenade = new Grenade(player->position);
		Sound::getInstance()->playYeetSound();
	}

	if (GInput::getInstance()->isMouseClick(0) && bullet == NULL)
	{
		bullet = new Bullet(player->position);
		Sound::getInstance()->playGunSound();
	}

	spawner->update();

	//Movement
	player->physic();

	//Check platform
	for (int i = 0; i < platformList.size(); i++)
	{
		platformList[i]->physic();
		if (isPlayerCollidePlatform(platformList[i]->position, platformList[i]->size))
		{
			isJump = true;
			player->speed.y = 0;
			player->position.y = platformList[i]->position.y - player->size.y;
		}

		if (platformList[i]->position.x <= -50)
			platformList.erase(platformList.begin() + i);
	}

	if (grenade != NULL)
		grenade->physic();

	if (bullet != NULL)
		bullet->physic();

	//Grenade hitbox
	if (grenade != NULL && grenade->position.y >= grenade->boundary)
	{
		for (int i = 0; i < spawnList.size(); i++)
		{
			if (isCollide(spawnList[i]->position, grenade->position, 100))
			{
				spawnList.erase(spawnList.begin() + i);
				score += 10;
			}
		}
		delete grenade;
		grenade = NULL;
	}

	//Coin Collider
	for (int i = 0; i < coinList.size(); i++)
	{
		coinList[i]->physic();
		if(isCollide(player->position, player->size, coinList[i]->position, coinList[i]->size))
		{
			coinList.erase(coinList.begin() + i);
			score += 5;
			Sound::getInstance()->playCoinSound();
			break;
		}
	}

	//Enemy activity
	for (int i = 0; i < spawnList.size(); i++)
	{
		spawnList[i]->physic();
		//check collision on enemy with player
		if (isPlayerCollideEnemy(spawnList[i]->position) || spawnList[i]->position.x <= 0)
		{

			if (isPlayerCollideEnemy(spawnList[i]->position))
			{
				player->lostHp();
				Sound::getInstance()->playDeathSound();
				if (player->getHp() <= 0)
				{
					GameStateManager::getInstance()->currentState = 2;
					Score::getInstance()->setValue(score);
					player->resetHp();
					score = 0;
				}
			}
			spawnList.erase(spawnList.begin() + i);
			break;
		}
	}

	if (bullet != NULL)
	{
		for (int i = 0; i < spawnList.size(); i++)
		{
			if (bullet->position.x >= 1000)
			{
				delete bullet;
				bullet = NULL;
				break;
			}
			else if (isCollide(spawnList[i]->position, bullet->position, 10))
			{
				spawnList.erase(spawnList.begin() + i);
				score += 10;
			}
		}
	}

}

void Scene::draw()
{
	sprite->Begin(D3DXSPRITE_ALPHABLEND);

	background->drawSprite(&sprite);

	//Coins
	for (int i = 0; i < coinList.size(); i++)
		sprite->Draw(resource, &coinList[i]->rect, NULL, &coinList[i]->position, D3DCOLOR_XRGB(255, 255, 255));

	//platform
	for (int i = 0; i < platformList.size(); i++)
		sprite->Draw(resource, &platformList[i]->rect, NULL, &platformList[i]->position, D3DCOLOR_XRGB(255, 255, 255));

	//Enemy
	for (int i = 0; i < spawnList.size(); i++)
		sprite->Draw(resource, &spawnList[i]->rect, NULL, &spawnList[i]->position, D3DCOLOR_XRGB(0, 255, 0));

	//Bullet
	if(bullet != NULL)
		sprite->Draw(resource, &bullet->rect, NULL, &bullet->position, D3DCOLOR_XRGB(105, 105, 105));

	//Grenade
	if(grenade != NULL)
		sprite->Draw(resource, &grenade->rect, NULL, &grenade->position, D3DCOLOR_XRGB(0, 255, 0));

	sprite->Draw(resource, &player->rect, NULL, &player->position, D3DCOLOR_XRGB(255, 255, 255));
	//Character
	sprite->Draw(resource, &player->rect, NULL, &player->position, D3DCOLOR_XRGB(255, 255, 255));

	gunActual = gun->getActualPosition(&player->position);
	//Gun
	sprite->Draw(resource, &gun->rect, NULL, &gunActual, D3DCOLOR_XRGB(255, 255, 255));

	//Mouse
	sprite->Draw(resource, &mouse, &mouseCenter, &mousePosition, D3DCOLOR_XRGB(255, 255, 255));


	//GUI
	gUI->drawSprite(&sprite,&resource,player->getHp(), &score);

	sprite->End();
}


bool Scene::isPlayerCollidePlatform(D3DXVECTOR3 objPos, D3DXVECTOR2 size)
{
	firstObjHitbox.left = player->position.x;
	firstObjHitbox.right = player->position.x + player->size.x;
	firstObjHitbox.top = player->position.y +90;
	firstObjHitbox.bottom = player->position.y + player->size.y;

	secondObjHitbox.left = objPos.x;
	secondObjHitbox.right = objPos.x + size.x;
	secondObjHitbox.top = objPos.y;
	secondObjHitbox.bottom = objPos.y + size.y;

	firstObjHitbox.left += 21;
	firstObjHitbox.right -= 12;

	if (firstObjHitbox.bottom < secondObjHitbox.top) return false;
	if (firstObjHitbox.top > secondObjHitbox.bottom) return false;
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
	secondObjHitbox.bottom = objPos.y + 97;

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

bool Scene::isCollide(D3DXVECTOR3 firstObjPos, D3DXVECTOR3 secondObjPos, int size)
{
	firstObjHitbox.left = firstObjPos.x;
	firstObjHitbox.right = firstObjPos.x + 42;
	firstObjHitbox.top = firstObjPos.y;
	firstObjHitbox.bottom = firstObjPos.y + 97;

	secondObjHitbox.left = secondObjPos.x - size;
	secondObjHitbox.right = secondObjPos.x + size;
	secondObjHitbox.top = secondObjPos.y - size;
	secondObjHitbox.bottom = secondObjPos.y + size;

	if (firstObjHitbox.bottom < secondObjHitbox.top) return false;
	if (firstObjHitbox.top > secondObjHitbox.bottom) return false;
	if (firstObjHitbox.right < secondObjHitbox.left) return false;
	if (firstObjHitbox.left > secondObjHitbox.right) return false;

	return true;
}
