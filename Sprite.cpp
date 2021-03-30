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

	player = new Character(3, 10, 200, 10, -8);

	setRenderPosition(&spriteRect);
	animationFrame = 0;

	characterSize.x = 61;
	characterSize.y = 97;

	characterPosition = { 10,150,0 };
}


void Sprite::update()
{

	animationFrame++;
	animationFrame %= 9;

	spriteRect.top = 0;
	spriteRect.left = characterSize.x * animationFrame;
	
	spriteRect.right = spriteRect.left + characterSize.x;
	spriteRect.bottom = spriteRect.top + characterSize.y;

	if (player->onFloor() || player->getJump())
	{
		player->setGravity(0);
		if (GInput::getInstance()->isKeyDown(DIK_W) && player->getJumpCurrent() > player->getJumpHeight())
		{
			player->setJump(true);
			player->jumpUp();
			
		}
		else
		{
			player->setJump(false);
			player->setJumpCurrent(0);
			
		}
	}
	else
	{
		player->setGravity(900);
	}


	player->gravityPull();

	if (GInput::getInstance()->isKeyDown(DIK_A))
	{
		player->moveright();
	}
	if (GInput::getInstance()->isKeyDown(DIK_D))
	{
		player->moveleft();
	}

}

void Sprite::drawSprite()
{
	//	Clear and begin scene

	sprite->Begin(D3DXSPRITE_ALPHABLEND);

	//background render
	//D3DXMatrixTransformation2D(&matrix, NULL, 0.0, &scaling, NULL, 0, &characterPos);
	//sprite->SetTransform(&matrix);


	//sprite->Draw(grenade, &grenadeRect, NULL, &player->position, D3DCOLOR_XRGB(255, 255, 255));
	sprite->Draw(resource, &spriteRect, NULL, &player->position, D3DCOLOR_XRGB(255, 255, 255));
	//	Sprite rendering. Study the documentation.
	//sprite->Draw(texture, NULL, NULL, NULL, D3DCOLOR_XRGB(255, 255, 255));

	//sprite->Draw(texture, &spriteRect, NULL, &drawPosition, D3DCOLOR_XRGB(255, 255, 255));


	//	End sprite drawing
	sprite->End();

	//	End and present scene
}



void Sprite::release()
{

	resource->Release();
	resource = NULL;;

	delete player;
	delete drawPosition;

	
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
