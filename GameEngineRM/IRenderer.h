#pragma once
#ifndef __I_RENDERER_H
#define __I_RENDERER_H
#include "utility/common.hpp"
#include "ShaderProgram.h"

namespace GameEngineM
{
	using namespace ShaderM;

	namespace RenderM
	{
		class IRenderer
		{
		protected:
			ShaderProgram _shaderProgram;

		public:
			IRenderer()=default;
			IRenderer(ShaderProgram shaderProgram);
			~IRenderer();

			virtual void init() = 0;
			virtual void start() = 0;
			virtual void render() = 0;
			virtual void stop() = 0;
			virtual void cleanup();

			void changeShaderProgram(ShaderProgram shaderProgram);
		};
	}
}
#endif /* __I_RENDERER_H */