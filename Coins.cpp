#include "Coins.h"


Coins::Coins(D3DXVECTOR3 position, float force, float sizeX, float sizeY, float left, float top) :Object(position, force, sizeX, sizeY, left, top)
{
	animationFrame = 0;
}

Coins::Coins()
{
	animationFrame = 0;
}

Coins::~Coins()
{
	animationFrame = NULL;
	Object::~Object();
}

void Coins::physic()
{
	position += speed / 60.0;
}

void Coins::animation()
{
	animationFrame++;
	animationFrame %= 6;

	rect.left = size.x * animationFrame;

	rect.right = rect.left + size.x;
	rect.bottom = rect.top + size.y;
}
