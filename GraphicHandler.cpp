#include "GraphicHandler.h"
#include "Windows.h"

GraphicHandler* GraphicHandler::sInstance = NULL;

GraphicHandler::GraphicHandler()
{
	this->direct3D9 = Direct3DCreate9(D3D_SDK_VERSION);
	ZeroMemory(&this->d3dPP, sizeof(this->d3dPP));

	ZeroMemory(&GameWindow::getInstance()->wndClass, sizeof(GameWindow::getInstance()->wndClass));
}

GraphicHandler* GraphicHandler::getInstance() {
	if (sInstance == NULL)
		sInstance = new GraphicHandler;

	return sInstance;
}
void GraphicHandler::releaseInstance() {
	if (sInstance != NULL) {
		delete sInstance;
		sInstance = NULL;
	}
}

void GraphicHandler::initialize() {
	d3dPP.Windowed = true;
	d3dPP.SwapEffect = D3DSWAPEFFECT_DISCARD;
	d3dPP.BackBufferFormat = D3DFMT_X8R8G8B8;
	d3dPP.BackBufferCount = 1;
	d3dPP.BackBufferWidth = 400;
	d3dPP.BackBufferHeight = 300;
	d3dPP.hDeviceWindow = GameWindow::getInstance()->g_hWnd;

	this->hr = direct3D9->CreateDevice(D3DADAPTER_DEFAULT, D3DDEVTYPE_HAL, GameWindow::getInstance()->g_hWnd, D3DCREATE_SOFTWARE_VERTEXPROCESSING, &d3dPP, &d3dDevice);

}
void GraphicHandler::draw() {
	//	To Do:
//	Update.

//	Clear the back buffer.
	d3dDevice->Clear(0, NULL, D3DCLEAR_TARGET, D3DCOLOR_XRGB(0, 255, 0), 1.0f, 0);

	//	Begin the scene
	d3dDevice->BeginScene();

	//	To Do:
	//	Drawing.

	//	End the scene
	d3dDevice->EndScene();

	//	Present the back buffer to screen
	d3dDevice->Present(NULL, NULL, NULL, NULL);


}

void GraphicHandler::clear() {
	d3dDevice->Release();
	d3dDevice = NULL;
}
