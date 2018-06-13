#include "Mouse.h"

using namespace GameEngineM;

Mouse::~Mouse()
{
}

void Mouse::center()
{
	glfwSetCursorPos(display->getWindow(), display->getWidth() / 2, display->getHeight() / 2);
	this->_xPos = (GLfloat)display->getWidth() / 2;
	this->_yPos = (GLfloat)display->getHeight() / 2;
	this->_dx = 0;
	this->_dy = 0;

	glfwSetInputMode(display->getWindow(), GLFW_CURSOR, GLFW_CURSOR_HIDDEN);
}