#pragma once
#include <d3dx9.h>
#include "Ginput.h"

class Bullet
{
private:
	D3DXVECTOR2 direction, position, speed;
	float force;
public:
	Bullet(D3DXVECTOR2* position);

	bool shoot();

	void physic();

};

