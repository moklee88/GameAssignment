#pragma once
#include <d3dx9.h>
#include "Object.h"
class Platform:public Object
{
private:

public:
	Platform();
	~Platform();

	Platform(D3DXVECTOR3 position, float force, float sizeX, float sizeY, float left, float top);

	void physic();

};

