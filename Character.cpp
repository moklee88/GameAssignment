#include "Character.h"

Character::Character(int hp, int x, int y, int height)
{
	this->hp = hp;

	this->speed = { 0,0,0 };

	this->position.x = x;
	this->position.y = y;
	this->position.z = 0;

	this->boundary = 350;
}




D3DXVECTOR3 Character::getPosition()
{
	return position;
}


void Character::physic()
{
	if (position.y <= 300)
	{
		speed.y += (200 / 60.0);
		position += (speed / 60.0);
	}
	else
		position.y = 300;
}

void Character::jump()
{
	speed.y = -200;
}

void Character::moveleft()
{
	speed.x++;
}
void Character::moveright()
{
	speed.x--;
}


void Character::animation()
{

}