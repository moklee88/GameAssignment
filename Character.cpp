#include "Character.h"

Character::Character(int hp, int x, int y, int speed)
{
	this->hp = hp;
	this->speed = speed;
	this->position.x = x;
	this->position.y = y;
	this->boundary = 100;
}


D3DXVECTOR2 Character::getPosition()
{
	return position;
}

bool Character::onFloor()
{
	if (position.x == boundary)
		return true;
}

void Character::moveleft()
{
	position.x += speed;
}
void Character::moveright()
{
	position.x -= speed;
}
void Character::jump()
{

}

void Character::animation()
{

}