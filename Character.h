#pragma once
#include <d3dx9.h>
class Character
{
private:

	int boundary;
	int hp;
	float force;


public:
	D3DXVECTOR3 position,speed;

	Character(int hp, int x, int y, int height);
	D3DXVECTOR3 getPosition();

	void physic();
	void stationary();

	void moveleft();
	void moveright();
	void jump();

	void death();

	void animation();

};

