#include "Grenade.h"

Grenade::Grenade(D3DXVECTOR2* position)
{
	this->position = { 53,34 };
	this->position += *position;

	direction = { 0,-1 };
	speed = { 0,0 };
	force = 200;
}

bool Grenade::launch()
{
	direction = GInput::getInstance()->getMousePosition() - position;
	D3DXVec2Normalize(&direction, &direction);

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