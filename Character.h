#pragma once
#include <d3dx9.h>
class Character
{
private:
	D3DXVECTOR2 position;
	int speed;
	int boundary;
	int hp;

public:

	Character(int hp, int x, int y, int speed);

	void moveleft();
	void moveright();
	void jump();

	D3DXVECTOR2 getPosition();

	bool onFloor();


};

