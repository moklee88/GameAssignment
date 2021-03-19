#include "Physic.h"


Physic::Physic(int x, int y)
{
	setPosition(x, y);

	boundary = 10;
}


D3DXVECTOR2 Physic::getPosition()
{
	return position;
}

void Physic::setPosition(int x, int y)
{
	position.x = x;
	position.y = y;
}
