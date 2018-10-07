#include "ShaderScript.h"
#include "Debug.h"
#include <memory>
#include <cstdarg>

using namespace GameEngineM;

void ShaderScript::compileShader()
{
	
	if (!_isCompiled)
	{
		debugMessage("Compiling shader.");
				
		glShaderSource(_shaderId, 1, (const_cast<const GLchar **>(&_shaderData)), NULL);
		glCompileShader(_shaderId);
		_isCompiled = true;			}
}

void ShaderScript::loadSourceShader()
{
	if (!_isLoaded)
	{
		debugMessage("Loading shader source");
		auto _data = readFile();
		if (!_data.empty())
		{
			debugInfo(_data);
			_shaderData = &_data[0];
			_isLoaded = true;
		}
		else
		{
			_isLoaded = false;
			//throw new ExceptionShaderFailedToLoad(_shaderId, _shaderType);
		}
	}
	return;
}

void ShaderScript::loadBinShader()
{
	//glShaderBinary(1,&_shaderType,); //incomplete...
}

void ShaderScript::logErrors()
{
	if (_isLoaded && _isCompiled)
	{
		GLint result = GL_FALSE;
		int logLength = 0;

		// Check vertex shader
		glGetShaderiv(_shaderId, GL_COMPILE_STATUS, &result);
		if (result == GL_FALSE) // Failed to compile
		{
			glGetShaderiv(_shaderId, GL_INFO_LOG_LENGTH, &logLength);
			if (logLength > 0) 
			{
				debugInfo("Shader compile failed, error log....");
				std::vector<char> shaderError(logLength);
				glGetShaderInfoLog(_shaderId, logLength, &logLength, &shaderError[0]);
				cout << &shaderError[0] << nl;
			}
			else
			{
				debugInfo("Failed to load shader compile errors????");
			}
		}
		else
		{
			debugInfo("Shader compiled succefully");
		}
	}
}

template<GLenum T>
ShaderScript::ShaderScript(string pathToSource)
	: ShaderScript(pathToSource,T)
{
}

ShaderScript::ShaderScript(string path, GLenum type)
{
	_shaderType = type;
	_shaderPath = path;

}

ShaderScript::~ShaderScript()
{
}

string ShaderScript::readFile()
{
	return readFile(_shaderPath);
}

string ShaderScript::readFile(string path)
{
	string content;
	ifstream fileStream{ path, ios::in };

	if (!fileStream.is_open()) {
		cerr << "Could not read file " << path << ". File does not exist." << nl;
	}

	string line = "";

	while (!fileStream.eof()) {
		getline(fileStream, line);
		content.append(line + "\n");
	}

	fileStream.close();
	_isLoaded = true;
	return content;
}