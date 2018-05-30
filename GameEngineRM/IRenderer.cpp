#include "IRenderer.h"

GameEngineM::IRenderer::IRenderer()
{
}

GameEngineM::IRenderer::IRenderer(ShaderM::IShaderProgram shaderProgram)
{
}

GameEngineM::IRenderer::~IRenderer()
{
}

void GameEngineM::IRenderer::attachShaderProgram(IShaderProgram shaderProgram)
{
	_shaderProgram = shaderProgram; // How to handle existing program?
}
