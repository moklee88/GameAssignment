#include "Grenade.h"

Grenade::Grenade(D3DXVECTOR3* position)
{
	this->position = { 53,34,0 };
	this->position += *position;

	size.x = 17;
	size.y = 23;

	direction = { 0,-1,0 };
	speed = { 0,0,0 };
	force = 200;

	rect.left = 558;
	rect.top = 11;
	rect.right = 581;
	rect.bottom = 39;
}

bool Grenade::launch()
{
	direction = GInput::getInstance()->getMousePosition() - position;
	D3DXVec3Normalize(&direction, &direction);

	speed = direction * force;

	return true;
}


void Grenade::physic()
{
	position += speed / 60.0;
	if (position.y <= 300)
	{
		speed.y += (200 / 60.0);
		position += (speed / 60.0);
	}
	else
	{
		speed.y = 0;
		position.y = 300;
		speed.x = -1;
	}
}