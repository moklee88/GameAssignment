#include "Sound.h"
#include <stdio.h>

Sound* Sound::sInstance = NULL;

Sound* Sound::getInstance()
{
	if (Sound::sInstance == NULL)
	{
		sInstance = new Sound;
	}

	return sInstance;
}

void Sound::releaseInstance()
{
	delete sInstance;
	sInstance = NULL;
}

Sound::Sound()
{
	system = NULL;

	yeetChannel = NULL;
	deathChannel = NULL;
	gunChannel = NULL;
	bgmChannel = NULL;
	coinChannel = NULL;

	yeetSound = NULL;
	deathSound = NULL;
	gunSound = NULL;
	bgmSound = NULL;

	FMOD::System_Create(&system);
	FMOD_RESULT result = FMOD::System_Create(&system);
	if (result != FMOD_OK) {
		printf("FMOD ERROR! (%d)\n", result);
	}

	result = system->init(512, FMOD_INIT_NORMAL, 0);

	if (result != FMOD_OK) {
		printf("FMOD ERROR! (%d)\n", result);
	}

	system->createSound("yeet.mp3", FMOD_DEFAULT, 0, &yeetSound);
	system->createSound("deathSound.mp3", FMOD_DEFAULT, 0, &deathSound);
	system->createSound("bgm.mp3", FMOD_DEFAULT, 0, &bgmSound);
	system->createSound("gunShot.mp3", FMOD_DEFAULT, 0, &gunSound);
	system->createSound("coin.mp3", FMOD_DEFAULT, 0, &coinSound);

}

void Sound::playYeetSound() {
	system->playSound(yeetSound, NULL, false, &yeetChannel);
	yeetSound->setMode(FMOD_LOOP_OFF);
}

void Sound::playDeathSound() {
	system->playSound(deathSound, NULL, false, &deathChannel);
	deathSound->setMode(FMOD_LOOP_OFF);
}

void Sound::playBgmSound() {
	system->playSound(bgmSound, NULL, false, &bgmChannel);
	bgmSound->setMode(FMOD_LOOP_NORMAL);
}

void Sound::playGunSound() {
	system->playSound(gunSound, NULL, false, &gunChannel);
	gunSound->setMode(FMOD_LOOP_OFF);
}

void Sound::playCoinSound() {
	system->playSound(coinSound, NULL, false, &coinChannel);
	coinSound->setMode(FMOD_LOOP_OFF);
}

Sound::~Sound()
{
	yeetSound->release();
	yeetSound = NULL;

	deathSound->release();
	deathSound = NULL;

	gunSound->release();
	gunSound = NULL;

	bgmSound->release();
	bgmSound = NULL;

	coinSound->release();
	coinSound = NULL;

	system->release();
	system = NULL;
}

