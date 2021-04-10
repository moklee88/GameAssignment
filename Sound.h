#pragma once
#include <fmod.hpp>

class Sound
{
private:
	static Sound* sInstance;
	FMOD::System* system;
	FMOD::Channel* yeetChannel;
	FMOD::Channel* deathChannel;
	FMOD::Channel* gunChannel;
	FMOD::Channel* coinChannel;
	FMOD::Channel* bgmChannel;

	FMOD::Sound* yeetSound;
	FMOD::Sound* deathSound;
	FMOD::Sound* gunSound;
	FMOD::Sound* coinSound;
	FMOD::Sound* bgmSound;

public:
	static Sound* getInstance();
	static void releaseInstance();

	void playYeetSound();
	void playDeathSound();
	void playBgmSound();
	void playGunSound();
	void playCoinSound();


	Sound();
	~Sound();
};

