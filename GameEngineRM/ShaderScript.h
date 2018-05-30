#pragma once
#ifndef __SHADER_SCRIPT_H
#define __SHADER_SCRIPT_H
/**
		Responsible for loading and maintaing a single shader script of any type.
		Can be used like : ShaderScript<GL_VERTEX_SHADER> objName { "path/to/script" };
*/
#include "utility/common.hpp"
#include "IShaderScript.h"

#include <vector>
namespace GameEngineM
{
	namespace ShaderM
	{
		class ShaderScript : public IShaderScript
		{
		private:

		public:
			
			void compileShader() override;
			void loadSourceShader() override;
			void loadBinShader() override;
			void logErrors() override;
			ShaderScript()=default;
			
			template<GLenum T>
			ShaderScript(string pathToSource);

			ShaderScript(string path, GLenum type);

			~ShaderScript();
		};
	}
}
#endif /* __SHADER_SCRIPT_H */