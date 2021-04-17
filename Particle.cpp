#include "Particle.h"
#include "Ginput.h"

Particle::Particle()
{
	particleRect.left = 7;
	particleRect.top = 234;
	particleRect.bottom = 244;
	particleRect.right = 18;

	for (int i = 0; i < 1000; i++)
	{
		position[i] = { -10,-10,0 };
		velocity[i] = { 0,0,0 };
	}
	
	speed = 10;
	index = 0;
	degree = 0;
	rad = 0;
	x = 0;
}

Particle::~Particle()
{
	particleRect.left = NULL;
	particleRect.top = NULL;
	particleRect.bottom = NULL;
	particleRect.right = NULL;

	for (int i = 0; i < 1000; i++)
	{
		position[i] = { NULL,NULL,NULL };
		velocity[i] = { NULL,NULL,NULL };
	}

	index = NULL;
	degree = NULL;
	rad = NULL;
	x = NULL;
}


void Particle::particleMovement() {
	for (int i = 0; i < 1000; i++)
	{
		position[i] += velocity[i];
	}
}
void Particle::particleSpawn(D3DXVECTOR3 enemyP)
{
	for (int i = 0; i < 100; i++)
	{
		position[index] = enemyP;

		degree = rand() % 360;
		rad = degree / 180.0 * 3.142;
		x = sin(rad);
		velocity[index].x = sin(rad) * speed;
		velocity[index].y = -cos(rad) * speed;

		index++;
		index %= 1000;
	}
}

void Particle::draw(LPD3DXSPRITE* sprite, LPDIRECT3DTEXTURE9* resource)
{
	for (int i = 0; i < 1000; i++)
	{
		(*sprite)->Draw(*resource, &particleRect, NULL, &position[i], D3DCOLOR_XRGB(255, 255, 255));
	}
}