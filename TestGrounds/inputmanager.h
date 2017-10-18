#pragma once

#include "utils.h"

#define BUTTON_UP 0
#define BUTTON_DOWN 1

//Current keybindings:

// w,a,s,d + arrow keys = move keys (up,left,down,right)
// left mouse button = shoot


struct KEY_PRESS	//Storage for key inputs
{
	int KEY_UP;
	int KEY_DOWN;
	int KEY_LEFT;
	int KEY_RIGHT;
	int KEY_SHOOT;

	KEY_PRESS()
	{
		KEY_UP = KEY_DOWN = KEY_LEFT = KEY_RIGHT = KEY_SHOOT = BUTTON_UP;
	}
};

class InputManager	//Static class
{
public:
	InputManager() = delete;

	static void Initialize();

	static KEY_PRESS keyStates;
	static glm::vec2 MousePos();

private:
	static void KeyboardDown(unsigned char key, int x, int y);
	static void KeyboardUp(unsigned char key, int x, int y);
	static void SpecialKeyDown(int key, int x, int y);
	static void SpecialKeyUp(int key, int x, int y);
	static void MouseMove(int x, int y);
	static void MouseAction(int button, int buttonState, int x, int y);

	static glm::ivec2 mousePos;
};