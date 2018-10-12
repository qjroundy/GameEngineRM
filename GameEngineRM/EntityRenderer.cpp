#include "EntityRenderer.h"
#include "ShaderScript.h"

void EntityRenderer::addEntities(IEntity * entity)
{
	_entities.push_back(entity);
}

void EntityRenderer::addEntities(vector<IEntity*> entities)
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