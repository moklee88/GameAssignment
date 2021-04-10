#pragma once
#include <d3dx9.h>
#include "Object.h"
class Coins : public Object
{
private:
	int animationFrame;
public:
	Coins(D3DXVECTOR3 position, float force, float sizeX, float sizeY, float left, float top);
	Coins();
	~Coins();

	void physic();
	void animation();
};

