
#include "utility/common.hpp"
#include "main/Main.h"

#include "Display.h"
using namespace DisplayM;

#include "GameEngine.h"
using namespace GameEngineM;

#include "IShaderProgram.h"
using namespace ShaderM;

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

	IShaderProgram shaderProgram( {"vertexShader.glsl", GL_VERTEX_SHADER}, {"fragmentShader.glsl",GL_FRAGMENT_SHADER} );

#ifndef AUTOBUILD_SHADERS
	shaderProgram[GL_VERTEX_SHADER].loadSourceShader();
	shaderProgram[GL_VERTEX_SHADER].compileShader();
	shaderProgram[GL_VERTEX_SHADER].logErrors();

	shaderProgram[GL_FRAGMENT_SHADER].loadSourceShader();
	shaderProgram[GL_FRAGMENT_SHADER].compileShader();
	shaderProgram[GL_FRAGMENT_SHADER].logErrors();
	shaderProgram.buildProgram();
#endif
	shaderProgram.start();

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