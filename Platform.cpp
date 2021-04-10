#include "Platform.h"


Platform::~Platform()
{
	Object::~Object();

}
Platform::Platform(D3DXVECTOR3 position, float force, float sizeX, float sizeY, float left, float top) :Object(position, force, sizeX, sizeY, left, top)
{

}

void Platform::physic()
{
	position += speed / 60.0;
}

