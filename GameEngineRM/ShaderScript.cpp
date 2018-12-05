#include "ShaderScript.h"
#include "Debug.h"
#include <memory>
#include <cstdarg>
#include <filesystem>



void ShaderScript::compileShader()
{
	
	if (!_isCompiled)
	{
		debugMessage("Compiling shader.");
				
		glShaderSource(_shaderId, 1, (const_cast<const GLchar **>(&_shaderData)), NULL);
		glCompileShader(_shaderId);
		_isCompiled = true;
	}
}

void ShaderScript::loadSourceShader()
{


	string binName = "cache/SCRIPT_" + getHashName() + ".bin";

	bool scriptExists = filesystem::exists(_shaderPath);
	bool binExists = filesystem::exists(binName);
	auto scriptLastWrite = filesystem::last_write_time(_shaderPath);
	auto binLastWrite = filesystem::last_write_time(binName);
	
	cout << "Script Exists: " << scriptExists << nl;
	cout << "Bin Exists: " << binExists << nl;
	//cout << "Script Last Write: " << scriptLastWrite.time_since_epoch << nl;
	//cout << "Bin Last Write: " << binLastWrite.time_since_epoch << nl;


	//auto age = scriptLastWrite.time_since_epoch - binLastWrite.time_since_epoch;
	//cout << age << nl;
	
	//bool scriptOlder = age < 0;

	//cout << scriptOlder << nl;

	if (filesystem::exists(binName.c_str()))
	{
		if (filesystem::last_write_time(binName.c_str()) > filesystem::last_write_time(_shaderPath))
		{
			_isLoaded = true;
			_isCompiled = true;
			// Load cached
		}
		else
		{
			// Load and build text script 
		}
	}
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
	unique_ptr<hash<string>> hasher{};

	auto path = "cache/SCRIPT_" + to_string((*hasher)(getName())) + ".bin";

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
	: _shaderId(glCreateShader(type))
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