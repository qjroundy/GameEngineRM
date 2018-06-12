#include "Mouse.h"

using namespace GameEngineM;

Mouse::~Mouse()
{
}

void Mouse::center()
{
	glfwSetCursorPos(Display.getWindow(), Display.getWidth() / 2, Display.getHeight() / 2);
	this->_xPos = (GLfloat)Display.getWidth() / 2;
	this->_yPos = (GLfloat)Display.getHeight() / 2;
	this->_dx = 0;
	this->_dy = 0;

	glfwSetInputMode(Display.getWindow(), GLFW_CURSOR, GLFW_CURSOR_HIDDEN);
}