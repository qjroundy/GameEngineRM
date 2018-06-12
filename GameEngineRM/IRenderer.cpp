#include "IRenderer.h"

using namespace GameEngineM::RenderM;
using namespace GameEngineM::ShaderM;

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