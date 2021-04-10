#include "Object.h"

Object::Object()
{

}
Object::Object(D3DXVECTOR3 position,float force, float sizeX, float sizeY, float left,float top)
{
	this->force = force;
	speed = { force,0,0 };

	this->position = position;

	size.x = sizeX;
	size.y = sizeY;
	
	rect.left = left;
	rect.top = top;
	rect.right = rect.left + size.x;
	rect.bottom = rect.top + size.y;
}

Object::~Object()
{
	force = NULL;
	speed = { NULL,NULL,NULL };
	position = { NULL,NULL,NULL };
	size = { NULL,NULL };
	rect = { NULL,NULL,NULL,NULL };
}

float Object::getForce()
{
	return force;
}
