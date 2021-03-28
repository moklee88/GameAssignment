#include "Character.h"

Character::Character(int hp, int x, int y, int speed, int height)
{
	this->hp = hp;

	this->speed = speed;
	this->jumpHeight = height;
	this->jump = false;
	this->jumpCurrent = 0;
	this->gravity = 10;

	this->position.x = x;
	this->position.y = y;
	this->position.z = 0;

	this->boundary = 200;
}


void Character::setGravity(int num)
{
	gravity = num;
}


int Character::getGravity()
{
	return gravity;
}

D3DXVECTOR3 Character::getPosition()
{
	return position;
}

int Character::getJumpHeight()
{
	return jumpHeight;
}

void Character::setJumpCurrent(int num)
{
	jumpCurrent = num;
}
int Character::getJumpCurrent()
{
	return jumpCurrent;
}

void Character::gravityPull()
{
	position.y += gravity;
}

bool Character::onFloor()
{
	if (position.y <= boundary)
		return false;

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
void Character::jumpUp()
{
	position.y -= 10;
	jumpCurrent -= 10;

}
void Character::setJump(bool current)
{
	jump = current;
}
bool Character::getJump()
{
	return jump;
}


void Character::animation()
{

}