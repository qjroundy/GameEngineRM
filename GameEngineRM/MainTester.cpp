
#include "utility/common.hpp"
#include "main/Main.h"
#include "IShaderProgram.h"
#include "GameEngine.h"
#include "Display.h"
#include "ShaderProgram.h"
#include "MasterRenderer.h"
#include "EntityRenderer.h"
#include "ModelMesh.h"
#include "ModelTexture.h"
#include "ModelTexturedMesh.h"
#include "IEntity.h"

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
	IShaderProgram* shaderProgram = new ShaderProgram;

	// This can be put into a class and done in init() call to that class....
#ifndef AUTOBUILD_SHADERS
	IShaderScript * shaderScript = new ShaderScript("scripts/vertexShader.glsl", GL_VERTEX_SHADER);
	shaderScript->loadSourceShader();
	shaderScript->compileShader();
	shaderScript->logErrors();
	shaderProgram->attachShader(shaderScript, GL_VERTEX_SHADER);	

	shaderScript = new ShaderScript("scripts/fragmentShader.glsl", GL_FRAGMENT_SHADER);
	shaderScript->loadSourceShader();
	shaderScript->compileShader();
	shaderScript->logErrors();
	shaderProgram->attachShader(shaderScript, GL_FRAGMENT_SHADER);
	
	shaderProgram->addAttribute(0, "position");
	shaderProgram->addAttribute(1, "textureCoords");
	shaderProgram->addAttribute(2, "normal");

	shaderProgram->addUniformName("transformationMatrix");
	//shaderProgram->addUniformName("projectionMatrix");

	std::cout << shaderProgram->getUniformLocation("transformationMatrix") << nl;
	shaderProgram->load();
	std::cout << shaderProgram->getUniformLocation("transformationMatrix") << nl;
#endif

	// create Master renderer
	debugInfo("Creating master Renderer");
	unique_ptr<MasterRenderer> masterRenderer(new MasterRenderer);

	// create individual renderers and add render elements
	debugInfo("Creating Entity Renderer");
	EntityRenderer* entityRenderer = new EntityRenderer;
	debugInfo("adding entity");

	//entityRenderer->addEntities(new IEntity{ new ModelMesh, new ModelTexture });

	// attach renderers to master
	debugInfo("Attaching entity renderer to master renderer");
	masterRenderer->attachRenderer(entityRenderer);

	debugMessage("Starting main loop");
	//game.startGameLoop();   // Thread?
	while (!display->shouldClose())
	{
		glClear(GL_CLEAR_BUFFER);

		//masterRenderer.start();

		//masterRenderer.render();
		glfwPollEvents();
		
		//masterRenderer.stop();
		glfwSwapBuffers(display->window());
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