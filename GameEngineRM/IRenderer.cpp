#include "IRenderer.h"

using namespace GameEngineM;
using namespace GameEngineM;

IRenderer::IRenderer(ShaderProgram shaderProgram)
	: _shaderProgram(shaderProgram)
{
}

IRenderer::~IRenderer()
{
}

void IRenderer::cleanup()
{
			
}

void IRenderer::changeShaderProgram(ShaderProgram shaderProgram)
{
	_shaderProgram = shaderProgram;
}