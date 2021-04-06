#include "Grenade.h"

Grenade::Grenade()
{

}
Grenade::Grenade(D3DXVECTOR3 position)
{
	this->position = { 53,34,0 };
	this->position += position;

	size.x = 21;
	size.y = 27;

	direction = { 0,-1,0 };
	speed = { 0,0,0 };
	force = 200;

	rect.left = 558;
	rect.top = 11;
	rect.right = 581;
	rect.bottom = 39;

	hitbox = { 0, 0, 0, 0 };

	boundary = 368;

	launch();
}
Grenade::~Grenade()
{
	position = { NULL,NULL,NULL };

	size.x = NULL;
	size.y = NULL;

	direction = { NULL,NULL,NULL };
	speed = { NULL,NULL,NULL };
	force = NULL;

	rect.left = NULL;
	rect.top = NULL;
	rect.right = NULL;
	rect.bottom = NULL;

	hitbox = { NULL,NULL,NULL, NULL};

	boundary = NULL;

}

void Grenade::launch()
{
	
	direction = GInput::getInstance()->getMousePosition() - position;
	D3DXVec3Normalize(&direction, &direction);

	speed = direction * force;

}


void Grenade::physic()
{
	position += speed / 60.0;
	if (position.y <= boundary)
	{
		speed.y += (200 / 60.0);
		position += (speed / 60.0);
	}
	else
	{
		speed.x = 1;
		position.y = boundary;
	}
}

RECT Grenade::getHitbox()
{
	
	hitbox.left = position.x + 4;
	hitbox.right = position.x + size.x;
	hitbox.top = position.y + 4;
	hitbox.bottom = position.y + size.y;

	return hitbox;
}

RECT Grenade::getExplosionHitbox()
{
	RECT hitbox;
	hitbox.left = position.x - 10;
	hitbox.right = position.x + size.x + 10;
	hitbox.top = position.y - 10;
	hitbox.bottom = position.y + size.y + 10;

	return hitbox;
}