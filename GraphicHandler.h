#pragma once
#include <d3d9.h>
#include "GameWindow.h"

class GraphicHandler
{
private:
	static GraphicHandler* sInstance;

	IDirect3D9* direct3D9;
	D3DPRESENT_PARAMETERS d3dPP;
	IDirect3DDevice9* d3dDevice;
	HRESULT hr;

public:
	GraphicHandler();

	static GraphicHandler* getInstance();
	static void releaseInstance();

	void initialize();
	void draw();
	void clear();
};

