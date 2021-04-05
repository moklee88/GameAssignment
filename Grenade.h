#pragma once
#include <d3dx9.h>
#include "Ginput.h"
class Grenade
{
private:
	D3DXVECTOR3 direction, speed;
	float force;
public:
	Grenade(D3DXVECTOR3* position);

	D3DXVECTOR3 position;
	bool launch();

	void physic();


};

