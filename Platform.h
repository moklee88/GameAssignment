#pragma once
#include <d3dx9.h>

class Platform
{
private:
	float force;
public:
	RECT rect;
	D3DXVECTOR3 direction, position, speed;
	Platform();
	~Platform();

	Platform(D3DXVECTOR3 position);

	void physic();

};

