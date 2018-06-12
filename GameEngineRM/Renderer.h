#pragma once

#ifndef __RENDERER_H
#define __RENDERER_H
#include "utility/common.hpp"
#include "IRenderer.h"

namespace GameEngineM
{
	namespace RenderM
	{

		class Renderer : public IRenderer
		{
		public:
			void start() override {};
			void stop() override {};
			void init() override {};
			void render() override {};

			Renderer()=delete;
			Renderer(ShaderProgram shaderProgram);
			~Renderer();
		};

	}
}
#endif /* __RENDERER_H */