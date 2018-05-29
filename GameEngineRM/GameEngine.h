#pragma once
#ifndef __GAME_ENGINE_H
#define __GAME_ENGINE_H
#include "utility/common.hpp"
#include "Game.h"

namespace GameEngineM
{

	class _GameEngine
	{
	private:
		_GameEngine();
		string _settings_file;
		

	public:
		_GameEngine(const _GameEngine& ) = delete;
		void operator=(const _GameEngine&) = delete;

		~_GameEngine();

		void Init();
		void Init(int, char**);

		void LoadSettings();
		Game& CreateGame();

		static _GameEngine& getInstance();
	};

	static _GameEngine& GameEngine = _GameEngine::getInstance();
}
#endif /* __GAME_ENGINE_H */