
#include "utility/common.hpp"
#include "main/Main.h"
#include <assimp/Importer.hpp>
#include "IShaderProgram.h"
#include "GameEngine.h"
#include "Display.h"

using namespace GameEngineM;
using namespace DisplayM;
using namespace ShaderM;



int main(int argc, char ** argv)
{
	// Splash screen????
	// Splash screeen start.....

	debugMessage("Loading Settings");
	GameEngine.LoadSettings();


	// Splash screen stop......

	debugMessage("Starting Engine");
	GameEngine.Init();
	

	debugMessage("Creating Game...");
	auto game = GameEngine.CreateGame();

	//debugMessage("Initializing ALUT");
	//alutInit(&argc, argv);

	//auto m = alcOpenDevice(NULL);
	//auto c = alcCreateContext(m, NULL);

	// Can we load shaders on a thread and just wait for all to finish loading? parralelle loading ?
	//ShaderM::setDefaultShaderPath("res/);
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
	//game.startGameLoop();   // Thread?
	while (!Display.shouldClose())
	{
		glClear(GL_CLEAR_BUFFER);

		glfwPollEvents();


		glfwSwapBuffers(Display.getWindow());
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