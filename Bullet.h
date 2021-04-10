#pragma once
#include <d3dx9.h>
#include "Ginput.h"

class Bullet
{
private:
	float force;
	//RECT hitbox;

public:
	RECT rect;
	D3DXVECTOR3 direction, position, speed;
	Bullet();
	~Bullet();
	Bullet(D3DXVECTOR3 position);

	void shoot();
	//RECT getHitbox();

	void physic();

};

