
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
#include "VertexShaderScript.h"
#include "FragmentShaderScript.h"
#include "PlayerShader.h"
#include "Player.h"
#include "EntityAnimalHostile.h"


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

	debugMessage("Initializing ALUT");
	alutInit(&argc, argv);

	auto m = alcOpenDevice(NULL);
	auto c = alcCreateContext(m, NULL);

	// Can we load shaders on a thread and just wait for all to finish loading? parralelle loading ?
	//ShaderM::setDefaultShaderPath("res/);
	unique_ptr<IShaderProgram> playerShaderProgram{ new PlayerShader() };

	// This can be put into a class and done in init() call to that class....
#ifndef AUTOBUILD_SHADERS
	IShaderScript * shaderScript = new VertexShaderScript("scripts/vertexShader.glsl");
	shaderScript->loadSourceShader();
	shaderScript->compileShader();
	shaderScript->logErrors();
	playerShaderProgram->attachShader(shaderScript, GL_VERTEX_SHADER);

	shaderScript = new FragmentShaderScript("scripts/fragmentShader.glsl");
	shaderScript->loadSourceShader();
	shaderScript->compileShader();
	shaderScript->logErrors();
	playerShaderProgram->attachShader(shaderScript, GL_FRAGMENT_SHADER);

	playerShaderProgram->addAttribute(0, "position");
	playerShaderProgram->addAttribute(1, "textureCoords");
	playerShaderProgram->addAttribute(2, "normal");

	playerShaderProgram->addUniformName("transformationMatrix");
	playerShaderProgram->addUniformName("projectionMatrix");

	std::cout << playerShaderProgram->getUniformLocation("transformationMatrix") << nl;
	playerShaderProgram->load();
	std::cout << playerShaderProgram->getUniformLocation("transformationMatrix") << nl;
#endif

	// create Master renderer
	debugInfo("Creating master Renderer");
	unique_ptr<MasterRenderer> masterRenderer(new MasterRenderer());

	// create individual renderers and add render elements
	debugInfo("Creating Entity Renderer");
	EntityRenderer* playerRenderer = new EntityRenderer();
	debugInfo("adding entity");
	playerRenderer->setShaderProgram(move(playerShaderProgram));

	//entityRenderer->addEntities(new IEntity{ new ModelMesh, new ModelTexture });

	// attach renderers to master
	debugInfo("Attaching entity renderer to master renderer");
	masterRenderer->attachRenderer(playerRenderer);
	
	debugMessage("Starting main loop");
	//game.startGameLoop();   // Thread?
	while (!display->shouldClose())
	{
		glClear(GL_CLEAR_BUFFER);

		//masterRenderer.start();

		//masterRenderer->render();
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