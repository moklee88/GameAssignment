#pragma once
#include <d3dx9.h>
#include "Ginput.h"
class Grenade
{
private:
	float force;
public:
	Grenade(D3DXVECTOR3* position);
	D3DXVECTOR2 size, explosionSize;

	RECT rect;
	D3DXVECTOR3 direction, speed, position;
	bool launch();

	void physic();

};

