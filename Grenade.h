#pragma once
#include <d3dx9.h>
#include "Ginput.h"
class Grenade
{
private:
	D3DXVECTOR2 direction, position, speed;
	float force;
public:
	Grenade(D3DXVECTOR2* position);

	bool launch();

	void physic();


};

