#pragma once

#ifndef __DISPLAY_H
#define __DISPLAY_H
#include "utility/common.hpp"

namespace DisplayM
{
	class _Display
	{
	private:
		GLint _width = 0;
		GLint _height = 0;
		GLint _fpsLimit = 15;
		GLFWwindow* _window;

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

		inline const GLint getWidth() const noexcept{ return _width; }
		inline const GLint getHeight() const noexcept{ return _height; }
		inline const GLint getFPSlimit() const noexcept{ return _fpsLimit; }
		inline const GLFWwindow* const getWindow() const noexcept { return _window; }
		bool shouldClose() const;

		void init();
		static _Display& getInstance();

	private:
		_Display();
		static void framebufferResize_callBack(GLFWwindow* window, int width, int height);
	};


}
	static DisplayM::_Display& Display = DisplayM::_Display::getInstance();


#endif /* __DISPLAY_H */

