#include "inputmanager.h"

KEY_PRESS InputManager::keyStates;
glm::ivec2 InputManager::mousePos(0, 0);

void InputManager::Initialize()
{
	glutKeyboardFunc(KeyboardDown);
	glutKeyboardUpFunc(KeyboardUp);

	glutSpecialFunc(SpecialKeyDown);
	glutSpecialUpFunc(SpecialKeyUp);

	glutMouseFunc(MouseAction);
	glutPassiveMotionFunc(MouseMove);
}

glm::vec2 InputManager::MousePos()
{
	return mousePos;
}

void InputManager::KeyboardDown(unsigned char key, int x, int y)
{
	switch (key)
	{
	case('w'):	//===== Movement controls (up, down, left, right)
	{
		keyStates.KEY_UP = BUTTON_DOWN;
		break;
	}
	case('s'):
	{
		keyStates.KEY_DOWN = BUTTON_DOWN;
		break;
	}
	case('a'):
	{
		keyStates.KEY_LEFT = BUTTON_DOWN;
		break;
	}
	case('d'):
	{
		keyStates.KEY_RIGHT = BUTTON_DOWN;
		break;
	}
	default:
		break;
	}
}

void InputManager::KeyboardUp(unsigned char key, int x, int y)
{
	switch (key)
	{
	case('w'):
	{
		keyStates.KEY_UP = BUTTON_UP;
		break;
	}
	case('s'):
	{
		keyStates.KEY_DOWN = BUTTON_UP;
		break;
	}
	case('a'):
	{
		keyStates.KEY_LEFT = BUTTON_UP;
		break;
	}
	case('d'):
	{
		keyStates.KEY_RIGHT = BUTTON_UP;
		break;
	}
	default:
		break;
	}
}

void InputManager::SpecialKeyDown(int key, int x, int y)
{
	switch (key)
	{
	case GLUT_KEY_UP:
	{
		keyStates.KEY_UP = BUTTON_DOWN;
		break;
	}
	case GLUT_KEY_DOWN:
	{
		keyStates.KEY_DOWN = BUTTON_DOWN;
		break;
	}
	case GLUT_KEY_LEFT:
	{
		keyStates.KEY_RIGHT = BUTTON_DOWN;
		break;
	}
	case GLUT_KEY_RIGHT:
	{
		keyStates.KEY_LEFT = BUTTON_DOWN;
		break;
	}
	default:
		break;
	}
}

void InputManager::SpecialKeyUp(int key, int x, int y)
{
	switch (key)
	{
	case GLUT_KEY_UP:
	{
		keyStates.KEY_UP = BUTTON_UP;
		break;
	}
	case GLUT_KEY_DOWN:
	{
		keyStates.KEY_DOWN = BUTTON_UP;
		break;
	}
	case GLUT_KEY_LEFT:
	{
		keyStates.KEY_RIGHT = BUTTON_UP;
		break;
	}
	case GLUT_KEY_RIGHT:
	{
		keyStates.KEY_LEFT = BUTTON_UP;
		break;
	}
	default:
		break;
	}
}

void InputManager::MouseMove(int x, int y)
{
	mousePos.x = x;
	mousePos.y = y;
}

void InputManager::MouseAction(int button, int buttonState, int x, int y)
{
	switch (button)
	{
	case 0:	//LEFT MOUSE BUTTON
	{
		keyStates.KEY_SHOOT = (buttonState == GLUT_DOWN) ? BUTTON_DOWN : BUTTON_UP;
		break;
	}
	default:
		break;
	}
}
