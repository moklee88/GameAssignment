#include "Gun.h"


Gun::Gun(D3DXVECTOR3* player, float sizeX, float sizeY, float left, float top)
{

	size.x = sizeX;
	size.y = sizeY;

	rect.left = left;
	rect.top = top;
	rect.right = rect.left + size.x;
	rect.bottom = rect.top + size.y;

	position = *player;
	move = { 47, 30, 0 };
}

Gun::~Gun()
{
	size.x = NULL;
	size.y = NULL;

	rect.left = NULL;
	rect.top = NULL;
	rect.right = NULL;
	rect.bottom = NULL;

	position = { NULL,NULL,NULL };
	move = { NULL,NULL,NULL };
}

D3DXVECTOR3 Gun::getActualPosition(D3DXVECTOR3* player)
{
	position = *player + move;
	return position;
}

