#pragma once

#ifndef __DISPLAY_H
#define __DISPLAY_H
#include "utility/common.hpp"

namespace GameEngineM {

	class _Display
	{
	private:
		GLFWwindow * _window;
		GLint _fpsLimit = 15;
		long _lastFrameTime = 0;
		float _delta = .02f;
		bool _isShown = false;
		bool _shouldClose = false;
	protected:

	public:
		_Display(_Display const&) = delete; // No reference copy
		void operator=(_Display const&) = delete; // Reference assign
		void createDisplay();
		void showDisplay();
		void hideDisplay();
		void closeDisplay();
		void updateDisplay();

		void resize(int width, int height);

		~_Display();

		GLint width = 0;
		GLint height = 0;
		inline GLFWwindow * const window()   { return _window; }
		bool shouldClose();
		inline const bool isShown() const  { return _isShown; }

		inline  const GLint	FPSlimit() const { return _fpsLimit; }
		//inline  GLFWwindow*	getWindow()		 { return _window; }

		void init();
		static _Display& getInstance();

	private:
		_Display();
		static void framebufferResize_callBack(GLFWwindow* window, int width, int height);
	};

	//static unique_ptr<_Display> display{ &_Display::getInstance() };
	//static shared_ptr<_Display> display{ &_Display::getInstance() };
	static _Display* display = &_Display::getInstance();
}

#endif /* __DISPLAY_H */

