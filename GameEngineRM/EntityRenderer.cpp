#include "EntityRenderer.h"
#include "ShaderScript.h"

using namespace GameEngineM;

void GameEngineM::EntityRenderer::addEntities(IEntity * entity)
{
	_entities.push_back(entity);
}

void GameEngineM::EntityRenderer::addEntities(vector<IEntity*> entities)
{
	_entities.insert(_entities.begin(),entities.begin(), entities.end());
}

EntityRenderer::EntityRenderer()
	//: Renderer({ {"entityVertexShader.glsl", GL_VERTEX_SHADER}, {"entityFragmentShader.glsl", GL_FRAGMENT_SHADER} })
	: Renderer()
{
}

EntityRenderer::~EntityRenderer()
{
}