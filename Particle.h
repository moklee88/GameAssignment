#pragma once
#include <d3dx9.h>

class Particle
{
private:
	
	D3DXVECTOR3 position[1000],velocity[1000];
	int index,degree;
	float rad, x;
	float speed;

public:
	RECT particleRect;
	Particle();
	~Particle();
	void particleMovement();
	void particleSpawn(D3DXVECTOR3 enemyP);
	void draw(LPD3DXSPRITE* sprite, LPDIRECT3DTEXTURE9* resource);
};

