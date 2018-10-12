#include "MasterRenderer.h"

using namespace GameEngineM;

void MasterRenderer::attachRenderer(IRenderer* renderer)
{
	_renderers.push_back(renderer);
}

void MasterRenderer::detachRenderer(IRenderer* renderer)
{
}

MasterRenderer::MasterRenderer(vector<IRenderer*> renderers)
{

}

MasterRenderer::~MasterRenderer()
{
}
