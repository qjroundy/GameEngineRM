
#include "main/Main.h"

#include "utility/common.hpp"


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

#ifdef DEBUG
	debugMessage("Setting up Graphics debugging");
	glfwWindowHint(GLFW_OPENGL_DEBUG_CONTEXT, true);
#endif

	debugMessage("Creating Display");
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE); // To make MacOS happy; should not be needed
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
	auto _window = glfwCreateWindow(1280, 720, "Test Window", NULL, NULL);
	if (!_window)
	{
		wcout << L"Window failed to create" << endl;
		glfwTerminate();
	}

	debugMessage("Showing Display");
	glfwMakeContextCurrent(_window);

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
	while (!glfwWindowShouldClose(_window))
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