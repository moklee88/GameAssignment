#pragma once
#include <d3dx9.h>
class Character
{
private:

	int boundary;
	int hp;


public:
	D3DXVECTOR3 position,speed;
	Character(int hp, int x, int y, int height);


	void physic();

	void moveleft();
	void moveright();
	void jump();

	D3DXVECTOR3 getPosition();


	void animation();

};

