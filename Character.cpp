#include "Character.h"

Character::Character(int hp, int x, int y, int height, float sizeX, float sizeY)
{
	this->hp = hp;

	this->speed = { 0,0,0 };
	this->force = 200;

	this->position.x = x;
	this->position.y = y;
	this->position.z = 0;

	this->size.x = sizeX;
	this->size.y = sizeY;

	this->boundary = 350;
}

Character::Character()
{
	this->force = 200;
	this->hp = 1;
	this->speed = { -force,0,0 };

	this->position.x = 580;
	this->position.y = 100;
	this->position.z = 0;

	this->boundary = 350;

}


void Character::physic()
{
	if (position.y <= 300)
	{
		speed.y += (200 / 60.0);
		position += (speed / 60.0);
	}
	else
	{
		speed.y = 0;
		position.y = 300;
	}
}

void Character::stationary()
{
	speed.x = 0;
}

void Character::jump()
{
	speed.y = -force;
}

void Character::moveright()
{
	speed.x = force;
}
void Character::moveleft()
{
	speed.x = -force;
}

void Character::lostHp()
{
	hp--;
}

void Character::death()
{

}

void Character::animation()
{

}