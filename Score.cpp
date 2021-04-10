#include "Score.h"
#include <cstddef>


Score* Score::sInstance = NULL;

Score* Score::getInstance()
{
	if (Score::sInstance == NULL)
	{
		sInstance = new Score;
	}

	return sInstance;
}

void Score::releaseInstance()
{
	delete sInstance;
	sInstance = NULL;
}

Score::Score()
{
	value = 0;
}

Score::~Score()
{
	value = NULL;
}

void Score::setValue(int num)
{
	value = num;
}
int Score::getValue()
{
	return value;
}
