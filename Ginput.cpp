#include "GInput.h"
#include "GameWindow.h"

GInput* GInput::sInstance = NULL;

GInput* GInput::getInstance() {
    if (sInstance == NULL) {
        sInstance = new GInput;
    }
    return sInstance;
}

void GInput::releaseInstance() {
    if (sInstance != NULL) {
        delete sInstance;
        sInstance = NULL;
    }
}

GInput::GInput()
{
    DirectInput8Create(GetModuleHandle(NULL), 0x0800, IID_IDirectInput8, (void**)&dInput, NULL);

    dInput->CreateDevice(GUID_SysKeyboard, &dInputKeyboardDevice, NULL);
    dInputKeyboardDevice->SetDataFormat(&c_dfDIKeyboard);
    dInputKeyboardDevice->SetCooperativeLevel(GameWindow::getInstance()->g_hWnd, DISCL_FOREGROUND | DISCL_NONEXCLUSIVE);
    ZeroMemory(diKeys, sizeof(diKeys));

    dInput->CreateDevice(GUID_SysMouse, &mouseDevice, NULL);
    mouseDevice->SetDataFormat(&c_dfDIMouse);
    mouseDevice->SetCooperativeLevel(GameWindow::getInstance()->g_hWnd, DISCL_FOREGROUND | DISCL_EXCLUSIVE);

    mousePosition.x = GameWindow::getInstance()->mouseX;
    mousePosition.y = GameWindow::getInstance()->mouseY;
}

GInput::~GInput()
{
    mouseDevice->Unacquire();
    mouseDevice->Release();
    mouseDevice = NULL;

    dInputKeyboardDevice->Unacquire();
    dInputKeyboardDevice->Release();
    dInputKeyboardDevice = NULL;

    dInput->Release();
    dInput = NULL;

}
void GInput::update()
{
    result = mouseDevice->GetDeviceState(sizeof(DIMOUSESTATE), (LPVOID)&mouseState);
    if (FAILED(result)) {
        if ((result == DIERR_INPUTLOST) || (result == DIERR_NOTACQUIRED)) {
            mouseDevice->Acquire();
        }
    }

    result = dInputKeyboardDevice->GetDeviceState(sizeof(diKeys), (LPVOID)&diKeys);
    if (FAILED(result))
    {
        if ((result == DIERR_INPUTLOST) || (result == DIERR_NOTACQUIRED)) {
            dInputKeyboardDevice->Acquire();
        }
    }

    mousePosition.x += mouseState.lX;
    mousePosition.x = max(mousePosition.x, 0);
    mousePosition.x = min(mousePosition.x, 550);

    mousePosition.y += mouseState.lY;
    mousePosition.y = max(mousePosition.y, 0);
    mousePosition.y = min(mousePosition.y, 550);
}
bool GInput::isKeyDown(int index) {
    return diKeys[index] & 0x80;
}

bool GInput::isMouseClick(int index) {
    return mouseState.rgbButtons[index] & 0x80;
}


D3DXVECTOR2 GInput::getMousePosition() {
    return mousePosition;
}
