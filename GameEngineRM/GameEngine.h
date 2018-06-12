#pragma once
#ifndef __GAME_ENGINE_H
#define __GAME_ENGINE_H

#include "utility/common.hpp"
#include "Game.h"

	namespace GameEngineM
	{
		enum EXIT_CODES
		{
			NO_GL_CONTEXT = -1,
			WINDOW_FAILED_TO_OPEN = -2,
			DEFAULT_FILE_MISSING = -3,
			GLEW_INIT_FAILED = -4,
			GLFW_INIT_FAILED = -5
		};

		
		class _GameEngine
		{
		private:
			_GameEngine();
			string _settings_file;

		public:
			_GameEngine(const _GameEngine&) = delete;
			void operator=(const _GameEngine&) = delete;

			~_GameEngine();

			void Init();
			void Init(int, char**);

			void LoadSettings();
			GameM::Game CreateGame();

			static _GameEngine& getInstance();
		};

		static _GameEngine& GameEngine = _GameEngine::getInstance();
	
}
#endif /* __GAME_ENGINE_H */