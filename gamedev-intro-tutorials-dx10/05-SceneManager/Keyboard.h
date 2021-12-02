#pragma once
#include "DirectXLibrary.h"
#include "Utils.h"
#define KEYBOARD_BUFFER_SIZE 1024 
#define DIRECTINPUT_VERSION 0x0800
#define KEYBOARD_STATE_SIZE 256
class Keyboard
{
	static Keyboard* __instance;
	LPDIRECTINPUT8       di;		// The DirectInput object         
	LPDIRECTINPUTDEVICE8 didv;		// The keyboard device
	BYTE  keyStates[KEYBOARD_STATE_SIZE];			// DirectInput keyboard state buffer 
	DIDEVICEOBJECTDATA keyEvents[KEYBOARD_BUFFER_SIZE];		// Buffered keyboard data
	HINSTANCE hInstance;
public:
	void Init(HWND hWnd);
	void Process();
	void OnKeyUp(int key);
	void OnKeyDown(int key);
	bool IsKeyDown(int key);
	static Keyboard* GetInstance();

};