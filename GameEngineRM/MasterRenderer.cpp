#include "MasterRenderer.h"

using namespace GameEngineM::RenderM;

void MasterRenderer::attachRenderer(Renderer renderer)
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
