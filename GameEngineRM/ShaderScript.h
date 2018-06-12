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
	class ShaderScript : public IShaderScript
	{
	private:
		string _shaderName; // USed for pretty output reasons...optional
	public:

		void compileShader() override;
		void loadSourceShader() override;
		void loadBinShader() override;
		void logErrors() override;
		ShaderScript() = default;

		template<GLenum T> ShaderScript(string path);

		ShaderScript(string path, GLenum type);
		void setName(string name) { _shaderName = name; }
		string getName() { return _shaderName; }
		~ShaderScript();
	};
}
#endif /* __SHADER_SCRIPT_H */