#include "Character.h"

Character::Character(int hp, int x, int y)
{
	this->hp = hp;

	this->speed = { 0,0,0 };
	this->force = 200;

	this->position.x = x;
	this->position.y = y;
	this->position.z = 0;


	rect.left = 0;
	rect.top = 0;
	rect.right = 0;
	rect.bottom = 0;

	this->size.x = 62;
	this->size.y = 97;

	this->boundary = 300;

	this->animationFrame = 0;

	timer = new FrameTimer();
	timer->init(GAME_FPS);
	framesToUpdate = 0;
}

Character::Character()
{
	this->force = 200;
	this->hp = 1;
	this->speed = { -force,0,0 };

	this->position.x = 600;
	this->position.y = 250;
	this->position.z = 0;

	rect.left = 0;
	rect.top = 98;
	rect.right = 0;
	rect.bottom = 0;

	this->size.x = 62;
	this->size.y = 97;

	this->boundary = 300;

	this->animationFrame = 0;

	timer = new FrameTimer;
	timer->init(GAME_FPS);
	framesToUpdate = 0;
}

Character::~Character()
{
	position = { NULL,NULL,NULL };
	speed = { NULL,NULL,NULL };
	size = { NULL,NULL };

	animationFrame = NULL;
	rect= { NULL,NULL,NULL,NULL };
	boundary = NULL;
	hp = NULL;
	force = NULL;

	delete timer;
	timer = NULL;
}


void Character::physic()
{
	framesToUpdate = timer->framesToUpdate();

	for (int i = 0; i < framesToUpdate; i++)
	{
		animation();
	}

	if (position.y <= boundary)
	{
		speed.y += (200 / 60.0);
		position += (speed / 60.0);
	}
	else
	{
		speed.y = 0;
		position.y = boundary;
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

int Character::getHp()
{
	return hp;
}

void Character::animation()
{
	animationFrame++;
	animationFrame %= 9;

	rect.left = size.x * animationFrame;

	rect.right = rect.left + size.x;
	rect.bottom = rect.top + size.y;
}