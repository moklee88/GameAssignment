#include "Platform.h"


Platform::~Platform()
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
Platform::Platform(D3DXVECTOR3 position)
{
	this->position = position;

	direction = { -1,0,0 };
	force = 150;
	speed = { force,0,0 };
	

	rect.left = 588;
	rect.top = 0;
	rect.right = 714;
	rect.bottom = 11;

}

void Platform::physic()
{
	position += speed / 60.0;
	speed = { force++,0,0 };
}

