#include "GameEngine.h"
#include "Display.h"
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

			debugMessage("Initializing GLFW");
			glfwInit();
			if (!glfwInit())
			{
				debugError("GLFW failed to initialize....", GLFW_INIT_FAILED);
			}

			Display.init();

			debugMessage("Initializing GLEW");
			glewExperimental = GL_TRUE;
			if (glewInit() != GLEW_OK) {
				debugError("Could not start GLEW", GLEW_INIT_FAILED);
			}

#ifdef DEBUG
			glEnable(GL_DEBUG_OUTPUT);
#endif
		}

		void _GameEngine::Init(int argc, char ** argv)
		{
			_settings_file = "conf/settings.xml";

			debugMessage("Initializing GLFW");
			glfwInit();
			if (!glfwInit())
			{
				debugError("GLFW failed to initialize....", GLFW_INIT_FAILED);
			}

			Display.init();

			debugMessage("Initializing GLEW");
			glewExperimental = GL_TRUE;
			if (glewInit() != GLEW_OK) {
				debugError("Could not start GLEW", GLEW_INIT_FAILED);
			}

		}

		void _GameEngine::LoadSettings()
		{
		}

		Game _GameEngine::CreateGame()
		{
			return Game{};
		}

		_GameEngine& _GameEngine::getInstance()
		{
			static _GameEngine __instance__;
			return __instance__;
			// TODO: insert return statement here
		}
}