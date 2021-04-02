#include "Bullet.h"

Bullet::Bullet(D3DXVECTOR2* position)
{
	this->position = { 53,34 };
	this->position += *position;

	direction = { 0,-1 };
	speed = { 0,0 };
	force = 200;
}

bool Bullet::shoot()
{
	direction = GInput::getInstance()->getMousePosition() - position;

	speed = direction * force;

	return true;
}


void Bullet::physic()
{
	position += speed / 60.0;

}
