#include "Mouse.h"

Mouse::~Mouse()
{
}

void Mouse::center()
{
	glfwSetCursorPos(display->window(), display->width / 2, display->height / 2);
	this->_xPos = (GLfloat)display->width	/ 2;
	this->_yPos = (GLfloat)display->height	/ 2;
	this->_dx = 0;
	this->_dy = 0;

	glfwSetInputMode(display->window(), GLFW_CURSOR, GLFW_CURSOR_HIDDEN);
}