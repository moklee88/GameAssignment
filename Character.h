#pragma once
#include <d3dx9.h>
#include <vector>

class Character
{
private:
	int boundary;
	int hp;
	float force;

public:
	D3DXVECTOR3 position,speed;
	D3DXVECTOR2 size;

	int animationFrame;
	RECT rect;

	Character(int hp, int x, int y);
	Character();
	~Character();

	void physic();
	void stationary();

	void moveleft();
	void moveright();
	void jump();

	void lostHp();
	int getHp();

	void animation();

};

