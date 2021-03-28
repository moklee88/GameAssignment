#pragma once
#include <d3dx9.h>
class Character
{
private:

	int speed;
	int boundary;
	int hp;
	int jumpHeight,jumpCurrent;
	int gravity;
	bool jump;

public:
	D3DXVECTOR3 position;
	Character(int hp, int x, int y, int speed, int height);

	void moveleft();
	void moveright();
	void jumpUp();

	D3DXVECTOR3 getPosition();
	int getJumpHeight();

	void setJump(bool current);
	bool getJump();

	void setJumpCurrent(int num);
	int getJumpCurrent();

	void setGravity(int num);
	int getGravity();

	void gravityPull();
	bool onFloor();

	void animation();

};

