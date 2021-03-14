#include "Sprite.h"

Sprite* Sprite::sInstance = NULL;

Sprite::Sprite()
{
	this->texture = NULL;
	this->sprite = NULL;
	//this->spriteRect = { 0,0,0,0 };
	setRenderPosition();
	this->hr = D3DXCreateSprite(GraphicHandler::getInstance()->getD3dDevice(), &sprite);
	this->hr = D3DXCreateTextureFromFile(GraphicHandler::getInstance()->getD3dDevice(), "dummy_walking.png", &texture);

	drawPosition.x = 32;
	drawPosition.y = 150;
	drawPosition.z = 0;
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

void Sprite::setRenderPosition()
{
	this->spriteRect.left = 0;
	this->spriteRect.top = 0;
	this->spriteRect.right = 57;
	this->spriteRect.bottom = 96;
}


void Sprite::drawSprite()
{
	//	Clear and begin scene

	sprite->Begin(D3DXSPRITE_ALPHABLEND);
	
	//	Sprite rendering. Study the documentation.
	//sprite->Draw(texture, NULL, NULL, NULL, D3DCOLOR_XRGB(255, 255, 255));
	//sprite->Draw(texture, &spriteRect, NULL, NULL, D3DCOLOR_XRGB(255, 255, 255));
	sprite->Draw(texture, &spriteRect, NULL, &drawPosition, D3DCOLOR_XRGB(255, 255, 255));
	
	//	End sprite drawing
	sprite->End();

	//	End and present scene
}

void Sprite::release()
{
	sprite->Release();
	sprite = NULL;

	texture->Release();
	texture = NULL;
}