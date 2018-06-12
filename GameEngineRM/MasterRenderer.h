#pragma once

#ifndef __MASTER_RENDERER_H
#define __MASTER_RENDERER_H
#include "utility/common.hpp"
#include "Renderer.h"

namespace GameEngineM
{
	namespace RenderM
	{

		class MasterRenderer 

			//:public IRenderer
		{
			vector<Renderer> _renderers;
		public:
			MasterRenderer()=default;
			MasterRenderer(vector<Renderer> renderers);

			void attachRenderer(Renderer renderer);
			void detachRenderer(Renderer renderer);
			//void init() override;
			//void start() override;
			//void render() override;
			//void stop() override;
			
			~MasterRenderer();
		};
	}
}
#endif /* __MASTER_RENDERER_H */