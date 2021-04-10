#pragma once
#include <d3dx9.h>
class Object
{
private:
	float force;
public:
	Object();
	Object(D3DXVECTOR3 position, float force, float sizeX, float sizeY, float left, float top);
	~Object();

	RECT rect;
	D3DXVECTOR2 size;
	D3DXVECTOR3 position, speed;

	float getForce();
	virtual void physic() = 0;

};

