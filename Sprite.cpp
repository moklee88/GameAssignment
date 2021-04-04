#include "Sprite.h"
#include "stdio.h"

Sprite* Sprite::sInstance = NULL;

Sprite::Sprite()
{

	grenadeRect.left = 0;
	grenadeRect.top = 0;
	grenadeRect.right = 0;
	grenadeRect.bottom = 0;

	playerRect.left = 0;
	playerRect.top = 0;
	playerRect.right = 0;
	playerRect.bottom = 0;

	enemyRect.left = 0;
	enemyRect.top = 0;
	enemyRect.right = 0;
	enemyRect.bottom = 0;

	this->hr = D3DXCreateSprite(GraphicHandler::getInstance()->getD3dDevice(), &sprite);

	this->hr = D3DXCreateTextureFromFile(GraphicHandler::getInstance()->getD3dDevice(), "resources.png", &resource);
	this->hr = D3DXCreateTextureFromFile(GraphicHandler::getInstance()->getD3dDevice(), "grenade.png", &grenade);

	animationFrame = 0;

	playerSize.x = 62;
	playerSize.y = 97;


	

}


void Sprite::update()
{
	//player animation
	animationFrame++;
	animationFrame %= 9;

	playerRect.top = 0;
	playerRect.left = playerSize.x * animationFrame;
	
	playerRect.right = playerRect.left + playerSize.x;
	playerRect.bottom = playerRect.top + playerSize.y;


	enemyRect.top = 98;
	enemyRect.left = playerSize.x * animationFrame;

	enemyRect.right = enemyRect.left + playerSize.x;
	enemyRect.bottom = enemyRect.top + playerSize.y;

}

void Sprite::drawSprite(Character* player, std::vector<Character*>& spawnList)
{
	//	Clear and begin scene

	sprite->Begin(D3DXSPRITE_ALPHABLEND);

	sprite->Draw(resource, &playerRect, NULL, &player->position, D3DCOLOR_XRGB(255, 255, 255));

	for (int i = 0; i < spawnList.size(); i++)
	{
		sprite->Draw(resource, &enemyRect, NULL, &spawnList[i]->position, D3DCOLOR_XRGB(255, 255, 255));
	}

	//	End sprite drawing
	sprite->End();

	//	End and present scene
}




void Sprite::release()
{
	sprite->Release();
	sprite = NULL;

	resource->Release();
	resource = NULL;

}

Sprite* Sprite::getInstance() {
	if (sInstance == NULL)
		sInstance = new Sprite();

	return sInstance;
}
void Sprite::releaseInstance() {
	if (sInstance != NULL) {
		delete sInstance;
		sInstance = NULL;
	}
}

RECT Sprite::getRenderPosition()
{
	return playerRect;
}
