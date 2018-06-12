
#include "utility/common.hpp"
#include "main/Main.h"
#include <assimp/Importer.hpp>
#include "IShaderProgram.h"
#include "GameEngine.h"
#include "Display.h"
#include "ShaderProgram.h"

using namespace GameEngineM;

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
	ShaderProgram shaderProgram( {"vertexShader.glsl", GL_VERTEX_SHADER}, {"fragmentShader.glsl",GL_FRAGMENT_SHADER} );

#ifndef AUTOBUILD_SHADERS
	shaderProgram[GL_VERTEX_SHADER].loadSourceShader();
	shaderProgram[GL_VERTEX_SHADER].compileShader();
	shaderProgram[GL_VERTEX_SHADER].logErrors();

	shaderProgram[GL_FRAGMENT_SHADER].loadSourceShader();
	shaderProgram[GL_FRAGMENT_SHADER].compileShader();
	shaderProgram[GL_FRAGMENT_SHADER].logErrors();

	shaderProgram.addAttribute(0, "position");
	shaderProgram.addAttribute(1, "textureCoords");
	shaderProgram.addAttribute(2, "normal");

	shaderProgram.addUniformName("transformationMatrix");
	shaderProgram.addUniformName("projectionMatrix");

	shaderProgram.load();
	cout << shaderProgram.getUniformLocation("transformationMatrix") << nl;
#endif

	debugMessage("Starting main loop");
	//game.startGameLoop();   // Thread?
	while (!Display.shouldClose())
	{
		shaderProgram.start();
		glClear(GL_CLEAR_BUFFER);

		glfwPollEvents();
		
		shaderProgram.stop();
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