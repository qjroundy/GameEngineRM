#include "Renderer.h"
#include "IRenderer.h"
#include "ShaderProgram.h"

using namespace GameEngineM::RenderM;
using namespace GameEngineM::ShaderM;

Renderer::Renderer(ShaderProgram shaderProgram)
	: IRenderer(shaderProgram)
{

}

Renderer::~Renderer()
{
}
