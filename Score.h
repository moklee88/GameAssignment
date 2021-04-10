#pragma once
class Score
{
private:
	static Score* sInstance;
	int value;
public:
	Score();
	~Score();
	static Score* getInstance();
	static void releaseInstance();

	void setValue(int num);
	int getValue();
};

