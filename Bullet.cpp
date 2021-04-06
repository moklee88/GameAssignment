#include "Bullet.h"

Bullet::Bullet()
{

}

Bullet::~Bullet()
{

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
	rect.right = 592;
	rect.bottom = 24;

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
