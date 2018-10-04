#include "Renderer.h"
#include "IRenderer.h"
#include "ShaderProgram.h"

using namespace GameEngineM;

void Renderer::changeShaderProgram(unique_ptr<IShaderProgram> shaderProgram)
{
	_shaderProgram = std::move(shaderProgram);
}

Renderer::Renderer(unique_ptr<IShaderProgram> shaderProgram)
	: IRenderer(), _shaderProgram(move(shaderProgram))
{

}

Renderer::~Renderer()
{
}

void Renderer::setShaderProgram(unique_ptr<IShaderProgram> shaderProgram)
{
	_shaderProgram = move(shaderProgram);
}

const IShaderProgram& Renderer::getShaderProgram(void)
{
	return *_shaderProgram;
}