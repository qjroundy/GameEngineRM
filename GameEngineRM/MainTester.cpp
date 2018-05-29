
#include "utility/common.hpp"
#include "main/Main.h"
#include "Display.h"
#include "GameEngine.h"

using namespace GameEngineM;
using namespace DisplayM;

int main(int argc, char ** argv)
{
	debugMessage("Starting Engine");
	GameEngine.Init();

	debugMessage("Loading Settings");
	GameEngine.LoadSettings();

	debugMessage("Creating Game...");
	auto game = GameEngine.CreateGame();

	//debugMessage("Initializing ALUT");
	//alutInit(&argc, argv);

	//auto m = alcOpenDevice(NULL);
	//auto c = alcCreateContext(m, NULL);

	debugMessage("Starting main loop");
	//game.startGameLoop();
	while (!Display.shouldClose())
	{
		glfwPollEvents();



	}
	
	debugMessage("Terminating GLFW system...");
	glfwTerminate();

	debugMessage("Terminating Game");
	//GameEngine.DestroyGame(game);

	debugMessage("Terminating Engine");
	//GameEngine.Destroy();

	cin.get();

	return 0;
}