#include "Sprite.h"
#include "stdio.h"

Sprite* Sprite::sInstance = NULL;

Sprite::Sprite()
{

	grenadeRect.left = 0;
	grenadeRect.top = 0;
	grenadeRect.right = 23;
	grenadeRect.bottom = 28;

	this->hr = D3DXCreateSprite(GraphicHandler::getInstance()->getD3dDevice(), &sprite);

	this->hr = D3DXCreateTextureFromFile(GraphicHandler::getInstance()->getD3dDevice(), "resources.png", &resource);
	this->hr = D3DXCreateTextureFromFile(GraphicHandler::getInstance()->getD3dDevice(), "grenade.png", &grenade);


	setRenderPosition(&spriteRect);
	animationFrame = 0;

	characterSize.x = 62;
	characterSize.y = 97;

}


void Sprite::update()
{
	animationFrame++;
	animationFrame %= 9;

	spriteRect.top = 0;
	spriteRect.left = characterSize.x * animationFrame;
	
	spriteRect.right = spriteRect.left + characterSize.x;
	spriteRect.bottom = spriteRect.top + characterSize.y;

}

void Sprite::drawSprite(Character* player)
{
	//	Clear and begin scene

	sprite->Begin(D3DXSPRITE_ALPHABLEND);

	sprite->Draw(resource, &spriteRect, NULL, &player->position, D3DCOLOR_XRGB(255, 255, 255));




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
	return spriteRect;
}

void Sprite::setRenderPosition(RECT *spriteRect)
{
	spriteRect->left = 0;
	spriteRect->top = 0;
	spriteRect->right = 61;
	spriteRect->bottom = 97;
}
