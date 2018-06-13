#include "MasterRenderer.h"

using namespace GameEngineM;

void MasterRenderer::attachRenderer(IRenderer* renderer)
{
	_renderers.push_back(renderer);
}

void MasterRenderer::detachRenderer(Renderer renderer)
{
}

MasterRenderer::MasterRenderer(vector<Renderer> renderers)
{

}

MasterRenderer::~MasterRenderer()
{
}
