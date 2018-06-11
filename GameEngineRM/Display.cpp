#include "Display.h"

namespace DisplayM
{
	_Display::_Display() 
	{
	}

	bool _Display::shouldClose() const
	{
		return (_shouldClose || (bool)glfwWindowShouldClose(_window))? true : false;
	}

	void _Display::init()
	{
		if (!_window)
		{
			createDisplay();
		}
		glfwMakeContextCurrent(_window);
	}

	void _Display::createDisplay()
	{
		debugMessage("Creating Display");
		glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
		glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 5);

#ifdef DEBUG
		glfwWindowHint(GLFW_OPENGL_DEBUG_CONTEXT, GL_TRUE);
		glEnable(GL_DEBUG_OUTPUT);
#endif
		glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE); // To make MacOS happy; should not be needed
		glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
		_window = glfwCreateWindow(1280, 720, "Test Window", NULL, NULL);
		if (!_window)
		{
			wcout << L"Window failed to create" << endl;
		}

		glfwSetFramebufferSizeCallback(_window, framebufferResize_callBack);
		glfwGetFramebufferSize(_window, &_width, &_height);
	}

	void _Display::showDisplay()
	{
		_isShown = true;
		glfwShowWindow(_window);
	}

	void _Display::hideDisplay()
	{
		_isShown = false;
		glfwHideWindow(_window);
	}

	void _Display::closeDisplay()
	{
		_isShown = false;
		_shouldClose = true;

		glfwDestroyWindow(_window);
	}

	void _Display::updateDisplay()
	{
		glfwSwapBuffers(_window);

		//auto currentFrameTime = time(0) * 1000;
		//_delta = (currentFrameTime - _lastFrameTime) / 1000.0f;
		//_lastFrameTime = currentFrameTime;
	}

	void _Display::resize(int width, int height)
	{
		glfwSetWindowSize(_window, width, height);
		glViewport(0, 0, width, height);
	}

	_Display::~_Display()
	{
		closeDisplay();
	}

	void _Display::framebufferResize_callBack(GLFWwindow* window, int width, int height)
	{
	}

	_Display& _Display::getInstance()
	{
		static _Display __instance__;
		return __instance__;
	}
}