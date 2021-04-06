#include "Scene.h"
#include "GraphicHandler.h"

Scene::Scene()
{
	bulletTimer = 0;
	grenade = NULL;
	player = new Character(3, 10, 200);
	firstObjHitbox = { 0,0,0,0 };
	secondObjHitbox = { 0,0,0,0 };

	mousePosition = { 0,0,0 };
	mouseCenter = { 26,26,0 };

	mouse = { 593,11,645,63 };

	ptrSpawnList = &spawnList;
	spawner = new Spawner(ptrSpawnList);

	D3DXCreateSprite(GraphicHandler::getInstance()->getD3dDevice(), &sprite);

	background = new Background();
	
	D3DXCreateTextureFromFile(GraphicHandler::getInstance()->getD3dDevice(), "resources.png", &resource);
}

Scene::~Scene()
{
	bulletTimer = NULL;

	release();
}

void Scene::init()
{

}

void Scene::fixUpdate()
{
	//Mouse
	mousePosition = GInput::getInstance()->getMousePosition() - (26, 26, 0);
	spawner->update();

	background->update();
	//Movement
	player->physic();

	if (grenade != NULL)
		grenade->physic();

	if (bulletTimer <= 1)
	{
		bulletTimer += 0.06;
	}

	for (int i = 0; i < bullets.size(); i++)
	{
		bullets[i]->physic();
		if(bullets[i]->position.x >= 700)
			bullets.erase(bullets.begin() + i);
	}

	//Enemy activity
	for (int i = 0; i < spawnList.size(); i++)
	{
		spawnList[i]->physic();
		//check collision on enemy enemy
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

	if (grenade != NULL && grenade->position.y >= grenade->boundary)
	{

		delete grenade;
		grenade = NULL;
	}
}

void Scene::update()
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

	//Launch Grenade
	if (GInput::getInstance()->isMouseClick(1) && grenade == NULL)
	{
		grenade = new Grenade(player->position);
	}

	if (GInput::getInstance()->isMouseClick(0) && bulletTimer >= 1)
	{
		bullet = new Bullet(player->position);
		bullets.push_back(bullet);
		bulletTimer = 0;
	}

}

void Scene::draw()
{
	
	sprite->Begin(D3DXSPRITE_ALPHABLEND);

	background->drawSprite(&sprite);

	//Enemy
	for (int i = 0; i < spawnList.size(); i++)
	{
		sprite->Draw(resource, &spawnList[i]->rect, NULL, &spawnList[i]->position, D3DCOLOR_XRGB(0, 255, 0));
	}
	//Bullet
	for (int i = 0; i < bullets.size(); i++)
	{
		sprite->Draw(resource, &bullets[i]->rect, NULL, &bullets[i]->position, D3DCOLOR_XRGB(105, 105, 105));
	}

	//Grenade
	if(grenade != NULL)
		sprite->Draw(resource, &grenade->rect, NULL, &grenade->position, D3DCOLOR_XRGB(0, 255, 0));

	//Character
	sprite->Draw(resource, &player->rect, NULL, &player->position, D3DCOLOR_XRGB(255, 255, 255));

	//Mouse
	sprite->Draw(resource, &mouse, &mouseCenter, &mousePosition, D3DCOLOR_XRGB(255, 255, 255));

	sprite->End();
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

	firstObjHitbox = { NULL,NULL };
	secondObjHitbox = { NULL,NULL };

	//Sprite Variable
	sprite = NULL;
	resource = NULL;


	for (int i = 0; i < spawnList.size(); i++)
	{
		delete spawnList[i];
		spawnList[i] = NULL;
	}
	delete grenade;
	grenade = NULL;

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

bool Scene::isCollide(D3DXVECTOR3 firstObjPos, RECT secondObjHitbox)
{
	firstObjHitbox.left = firstObjPos.x;
	firstObjHitbox.right = firstObjPos.x + 42;
	firstObjHitbox.top = firstObjPos.y;
	firstObjHitbox.bottom = firstObjPos.y + 11;

	firstObjHitbox.left += 21;
	firstObjHitbox.right -= 12;

	if (firstObjHitbox.bottom < secondObjHitbox.top) return false;
	if (firstObjHitbox.top > secondObjHitbox.bottom) return false;
	if (firstObjHitbox.right < secondObjHitbox.left) return false;
	if (firstObjHitbox.left > secondObjHitbox.right) return false;

	return true;
}
