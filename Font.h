#pragma once
#include <string>
#include <d3dx9.h>

using namespace std;

extern class Font
{
private:
	
public:
	Font();
	~Font();
	Font(LPCSTR word, float x, float y, float sizeX, float sizeY);
	RECT position;
	LPCSTR word;
};

