#include "Font.h"

Font::Font()
{
	position = { 0,0,0,0 };
	word = "Test";
}
Font::Font(LPCSTR word, float x, float y, float sizeX, float sizeY)
{
	position.left = x;
	position.top = y;
	position.right = position.left + sizeX;
	position.bottom = position.top + sizeY;

	this->word = word;
}
Font::~Font()
{
	position = { NULL,NULL,NULL,NULL };
	word = NULL;
}