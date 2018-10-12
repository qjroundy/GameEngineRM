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

class ShaderScript : public IShaderScript
{
private:
	bool _isCompiled = false;
	bool _isLoaded = false;
	bool _isTypeKnown = false;
	bool _isSaved = false;
	GLenum _shaderType = 0;
	GLuint _shaderId = 0;
	GLchar * _shaderData{};
	string _shaderName{}; // Used for pretty output reasons...optional
	string _shaderPath{};
	string _hashName{};

public:
	inline const bool isLoaded() override { return _isLoaded; }
	inline const bool isCompiled() override { return _isCompiled; }
	inline const bool isTypeKnown() override { return _isTypeKnown; }
	inline const bool isSaved() override { return _isSaved; }
	inline const GLuint shaderId() override { return _shaderId; }
	inline const GLuint getShaderId() override { return _shaderId; }
	string readFile() override;
	string readFile(string) override;

	void compileShader() override;
	void loadSourceShader() override;
	void loadBinShader() override;
	void logErrors() override;
	void cleanUp() override {}
	template<GLenum T> ShaderScript(string path);

	inline virtual void setName(string name) 
	{
		_shaderName = name;

		getHashName();

	}

	inline virtual const string& getHashName()
	{
		unique_ptr<hash<string>> hasher{};

		if (_hashName.empty())
		{
			if (_shaderName.empty())
			{
					
				return _hashName = to_string((*hasher)(_shaderPath));
			}
			else
			{
				return _hashName = to_string((*hasher)(_shaderName));
			}
		}
			
		return _hashName;
	}

	inline virtual const string& getName() 
	{
		if (_shaderName.empty())
		{
			return _shaderPath;
		}
		else
		{ 
			return _shaderName; 
		}
	}

	ShaderScript() = default;
	ShaderScript(string path, GLenum type);
	~ShaderScript();
};

#endif /* __SHADER_SCRIPT_H */