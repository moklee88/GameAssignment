#pragma once
#include <d3dx9.h>
class Physic
{
private:
	D3DXVECTOR2 position;
	int boundary;

public:

	Physic(int x, int y);
	void gravity();

	D3DXVECTOR2 getPosition();
	void setPosition(int x, int y);



};

