#include "Bullet.h"

Bullet::Bullet()
{

}

Bullet::~Bullet()
{
	this->position = { NULL,NULL,NULL };

	direction = { NULL,NULL,NULL };
	speed = { NULL,NULL,NULL };
	force = NULL;

	rect.left = NULL;
	rect.top = NULL;
	rect.right = NULL;
	rect.bottom = NULL;
}
Bullet::Bullet(D3DXVECTOR3 position)
{
	this->position = { 53,34,0 };
	this->position += position;

	direction = { 1,0,0 };
	speed = { 0,0,0 };
	force = 200;

	rect.left = 581;
	rect.top = 11;
	rect.right = 587;
	rect.bottom = 18;

	shoot();
}

void Bullet::shoot()
{
	//direction = GInput::getInstance()->getMousePosition() - position;

	speed = direction * force;
}


void Bullet::physic()
{
	position += speed / 60.0;
}
