#pragma once
#include <d3dx9.h>
class Gun
{
private:

public:
	Gun();
	~Gun();
	Gun(D3DXVECTOR3* player, float sizeX, float sizeY, float left, float top);
	RECT rect;
	D3DXVECTOR2 size;
	D3DXVECTOR3 position, move, finalP;

	D3DXVECTOR3 getActualPosition(D3DXVECTOR3* player);
};

