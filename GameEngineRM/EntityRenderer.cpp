#include "EntityRenderer.h"
#include "ShaderScript.h"

using namespace GameEngineM;

EntityRenderer::EntityRenderer()
	: Renderer({ {"entityVertexShader.glsl", GL_VERTEX_SHADER}, {"entityFragmentShader.glsl", GL_FRAGMENT_SHADER} })
{
}

EntityRenderer::~EntityRenderer()
{
}