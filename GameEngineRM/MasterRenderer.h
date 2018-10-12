#pragma once

#ifndef __MASTER_RENDERER_H
#define __MASTER_RENDERER_H
#include "utility/common.hpp"
#include "Renderer.h"
#include <vector>

namespace GameEngineM
{
	class MasterRenderer

		//:public IRenderer
	{
		vector<IRenderer*> _renderers;
	public:
		MasterRenderer() = default;
		MasterRenderer(vector<IRenderer*> renderers);

		void attachRenderer(IRenderer* renderer);
		void detachRenderer(IRenderer* renderer);

		~MasterRenderer();
	};
}
#endif /* __MASTER_RENDERER_H */