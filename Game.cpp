#include "Game.h"

void Game::initia()
{
	background = new Background;
	character = new Character;
	object = new Object;
	physic = new Physic;

	background->initia();
	character->initia();
	object->initia();
	sprite = NULL;
	isLose = false;
	physic->isJump = false;
	count = 0;

	D3DXCreateFont(Graphic::getInstance()->d3dDevice, 35, 0, 0, 1, false,
				   DEFAULT_CHARSET, OUT_TT_ONLY_PRECIS, DEFAULT_QUALITY,
				   DEFAULT_PITCH | FF_DONTCARE, "Segoe Script", &score);

	rectScore.left = 0;
	rectScore.top = 0;
	rectScore.right = 400;
	rectScore.bottom = 50;

	rectRestart.left = 50;
	rectRestart.top = 250;
	rectRestart.right = 350;
	rectRestart.bottom = 450;

}
void Game::update()
{
	Audio::getInstance()->play(4);
	//lose condition
	if (character->characterPos.y > 600)
	{
		isLose = true;
		object->pPosList.clear();
		object->brokenpPosList.clear();
		object->cPosList.clear();
		if (count == 0) //play once only
		{
			Audio::getInstance()->play(3);
			character->characterPos.y = 0;
			count++;
		}
	}
	
	background->update(); 
	character->update(); //movement

	if (!isLose)
	{
		if (physic->isJump)
		{
			physic->velocity -= 0.1;
			physic->jumpingHeight += physic->velocity - physic->gravity;
		}
		else
		{
			for (int i = 0; i < object->pPosList.size(); i++)
			{
				if (physic->isCollide(character->characterPos, character->characterSize*SCALING, object->pPosList[i], object->platformSize, character->state, /*top adjust*/character->characterSize.y*SCALING))
				{
					Audio::getInstance()->play(0);
					character->jumpAnimation(character->state);
					physic->isJump = true;
					physic->velocity = 10;
					printf("collision detected\n");
					break;
				}
			}
			for (int i = 0; i < object->brokenpPosList.size(); i++)
			{
				if (!object->isDestroy[i] && physic->isCollide(character->characterPos, character->characterSize*SCALING, object->brokenpPosList[i], object->platformSize, character->state, character->characterSize.y*SCALING))
				{
					Audio::getInstance()->play(1);
					object->isDestroy[i] = true;
					printf("OH NO ITS A TRAP\n");
					break;
				}
			}
		}
		for (int i = 0; i < object->cPosList.size(); i++)
		{
			if (physic->isCollide(character->characterPos, character->characterSize*SCALING, object->cPosList[i], object->coinSize, character->state, 0))
			{
				Audio::getInstance()->play(2);
				object->cPosList.erase(object->cPosList.begin() + i);
				object->coinNum--;
				object->countScore += 40;
				printf("MONEYMONEYMONEY ! ! ! \n");
				break;
			}
		}
		if (physic->jumpingHeight >= 120)
		{
			physic->jumpingHeight = 0;
			physic->isJump = false;
			physic->velocity = 0;
		}

		character->characterPos.y = character->characterPos.y - physic->velocity + physic->gravity;
		character->characterPos = object->fakeScrolling(character->characterPos);
		scoreStr = std::to_string(object->countScore);
		object->update();
	}
	else
	{
		character->characterPos.y += physic->gravity;
	}
}
void Game::fixedUpdate()
{
	character->fixedUpdate();
	object->fixedUpdate();
}

void Game::draw()
{
	background->draw();
	object->draw();
	score->DrawText(sprite, scoreStr.c_str(), -1, &rectScore, DT_CENTER, D3DCOLOR_XRGB(102, 71, 51));
	if (isLose)
	{
		score->DrawText(sprite, "You Lose... \nPress \"R\" to Restart!", -1, &rectRestart, DT_CENTER, D3DCOLOR_XRGB(51, 0, 51));
	}
	character->draw();
}
void Game::release()
{
	score->Release();
	score = NULL;

	background->release();
	character->release();
	object->release();
	delete background;
	delete character;
	delete object;
	delete physic;
}

//github testing 123