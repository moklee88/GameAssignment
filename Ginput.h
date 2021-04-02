#pragma once
#include <dinput.h>
#include <d3dx9.h>
class GInput
{
private:
    BYTE  diKeys[256];
    LPDIRECTINPUT8 dInput;
    DIMOUSESTATE mouseState;

    LPDIRECTINPUTDEVICE8  dInputKeyboardDevice;
    LPDIRECTINPUTDEVICE8 mouseDevice;

    D3DXVECTOR2 mousePosition;
    HRESULT result;
    
    static GInput* sInstance;
    GInput();
    ~GInput();
public:
    static GInput* getInstance();
    static void releaseInstance();
    void update();
    
    bool isKeyDown(int index);
    bool isMouseClick(int index);
    D3DXVECTOR2 getMousePosition();

};