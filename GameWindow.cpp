#include "GameWindow.h"
//#include "resource.h"
#include <stdio.h>

GameWindow* GameWindow::sInstance = NULL;

//	Window Procedure, for event handling
LRESULT CALLBACK WindowProcedure(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	switch (message)
	{
		//	The message is post when we destroy the window.
	case WM_DESTROY:
		PostQuitMessage(0);
		break;

	case WM_KEYDOWN:
		if (wParam == VK_ESCAPE) {
			PostQuitMessage(0);
		}
		printf("%d\n", wParam);
		break;

		//case VK_ESCAPE:
		//	return(0);
		//	break;
			//	Default handling for other messages.
	default:
		return DefWindowProc(hWnd, message, wParam, lParam);
	}
	return 0;
}

GameWindow* GameWindow::getInstance() {
	if (sInstance == NULL)
		sInstance = new GameWindow;

	return sInstance;
}

void GameWindow::releaseInstance() {
	if (sInstance != NULL) {
		delete sInstance;
		sInstance = NULL;
	}
}

GameWindow::GameWindow() {
	this->hInstance = GetModuleHandle(NULL);
	this->g_hWnd = NULL;
	ZeroMemory(&this->wndClass, sizeof(this->wndClass));

}


int GameWindow::createWindow() {

	/*
	Step 1
	Define and Register a Window.
*/

//	Window's structure
	//WNDCLASS wndClass;
	//	Sset all members in wndClass to 0.
	//ZeroMemory(&wndClass, sizeof(wndClass));

	//	Filling wndClass. You are to refer to MSDN for each of the members details.
	//	These are the fundamental structure members to be specify, in order to create your window.
	wndClass.hbrBackground = (HBRUSH)GetStockObject(BLACK_BRUSH);
	wndClass.hCursor = LoadCursor(GetModuleHandle(NULL), IDC_ARROW/*MAKEINTRESOURCE(IDC_CURSOR1)*/);
	wndClass.hInstance = hInstance; //GetModuleHandle(NULL);
	wndClass.lpfnWndProc = WindowProcedure;
	wndClass.lpszClassName = "My Window";
	wndClass.style = CS_HREDRAW | CS_VREDRAW;
	//wndClass.hIcon = LoadIcon(GetModuleHandle(NULL), MAKEINTRESOURCE(IDI_ICON1));

	//	Register the window.
	RegisterClass(&wndClass);

	/*
		Step 2
		Create the Window.
	*/
	//	You are to refer to MSDN for each of the parameters details.
	g_hWnd = CreateWindowEx(0, wndClass.lpszClassName, "My Window's Name", WS_OVERLAPPEDWINDOW, 300, 300, 550, 450, NULL, NULL, hInstance, NULL);
	ShowWindow(g_hWnd, 1);

	return 0;
}

void GameWindow::removeWindow() {
	//	Free up the memory.

	UnregisterClass(wndClass.lpszClassName, hInstance);

}

bool GameWindow::loop() {
	MSG msg;
	ZeroMemory(&msg, sizeof(msg));

	while (PeekMessage(&msg, NULL, 0, 0, PM_REMOVE))
	{
		//	Receive a quit message
		if (msg.message == WM_QUIT) break;
		//	Translate the message 
		TranslateMessage(&msg);
		//	Send message to your window procedure
		DispatchMessage(&msg);
	}

	//graphic section

	//}
	if (msg.message != WM_QUIT) {
		return true;
	}
	else
		return false;


}