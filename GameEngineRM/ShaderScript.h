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
		bool _isCompiled = false;
		bool _isLoaded = false;
		bool _isTypeKnown = false;
		bool _isSaved = false;
		GLuint _shaderId = 0;
		GLchar * _shaderData{};
		string _shaderPath = "";
		GLenum _shaderType = 0;
		string _shaderName; // USed for pretty output reasons...optional
	public:
		inline const bool isLoaded() override { return _isLoaded; }
		inline const bool isCompiled() override { return _isCompiled; }
		inline const bool isTypeKnown() override { return _isTypeKnown; }
		inline const bool isSaved() override { return _isSaved; }
		inline const GLuint shaderId() override { return _shaderId; }
		inline const GLuint getShaderId() override { return _shaderId; }
		string readFile();
		string readFile(string);

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