#pragma once
#include <Windows.h>

class FrameTimer
{
private:
	LARGE_INTEGER timer_freq;
	LARGE_INTEGER time_now;
	LARGE_INTEGER time_previous;
	int requested_FPS;
	float intervalsPerFrame;

public:
	FrameTimer();
	~FrameTimer();
	void init(int fps);
	int framesToUpdate();


};

