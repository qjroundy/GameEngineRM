#include "GameEngine.h"
namespace GameEngineM {
	_GameEngine::_GameEngine()
	{
	}


	_GameEngine::~_GameEngine()
	{
	}

	void _GameEngine::Init()
	{
		_settings_file = "conf/settings.xml";


	}

	void _GameEngine::Init(int argc, char ** argv)
	{

	}

	void _GameEngine::LoadSettings()
	{
	}

	Game & _GameEngine::CreateGame()
	{
		r
		// TODO: insert return statement here
	}

	_GameEngine& _GameEngine::getInstance()
	{
		static _GameEngine __instance__;
		return __instance__;
		// TODO: insert return statement here
	}
}