
#include "main/Main.h"

#include "utility/common.hpp"
#include "Display.h"

int main(int argc, char ** argv)
{

	debugMessage("Starting Engine");
	// GAMEENGINE::INIT();

	debugMessage("Creating Game...");
	// auto game = GAMEENGINE::CREATE_GAME();

	debugMessage("Initializing GLFW");
	glfwInit();	
	//if (!glfwInit())
	//{
	//	wcerr << L"GLFW failed to initialize...." << nl;
	//	//exit(ERROR::ERROR_CODES::GLFW_INIT_FAILED);
	//}


	DisplayM::Display.init();

	debugMessage("Initializing GLEW");
	glewExperimental = GL_TRUE;
	if (glewInit() != GLEW_OK) {
		wcerr << L"Could not start GLEW" << nl;
		std::cin.get();
		//exit(EXIT_CODES::GLEW_INIT_FAILED);
	}

#ifdef DEBUG
//	glEnable(GL_DEBUG_OUTPUT);
#endif

	debugMessage("Initializing ALUT");
	alutInit(&argc, argv);

	auto m = alcOpenDevice(NULL);
	auto c = alcCreateContext(m, NULL);

	debugMessage("Starting main loop");
	//game.startGameLoop();
	while (!DisplayM::Display.shouldClose())
	{

		glfwPollEvents();

	}


	debugMessage("Terminating GLFW system...");
	glfwTerminate();

	debugMessage("Terminating Game");
	// GAMEENGINE::DESTROY_GAME(game);
	debugMessage("Terminating Engine");
	// GAMEENGINE::DESTROY();

	char t;
	cin >> t;

	return 0;
}