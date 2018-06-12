#include "Renderer.h"
#include "IRenderer.h"
#include "ShaderProgram.h"

using namespace GameEngineM;

Renderer::Renderer(ShaderProgram shaderProgram)
	: IRenderer(shaderProgram)
{

}

Renderer::~Renderer()
{
}
