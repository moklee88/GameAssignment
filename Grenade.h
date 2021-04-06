#pragma once
#include <d3dx9.h>
#include "Ginput.h"
class Grenade
{
private:
	float force;
	RECT hitbox;

public:
	Grenade();
	Grenade(D3DXVECTOR3 position);
	~Grenade();
	D3DXVECTOR2 size, explosionSize;
	int boundary;

	RECT rect;
	D3DXVECTOR3 direction, speed, position;
	void launch();

	RECT getHitbox();
	RECT getExplosionHitbox();
	void physic();

};

