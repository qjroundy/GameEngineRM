#include "IShaderScript.h"
#include <vector>

using namespace GameEngineM;

template<GLenum T>
IShaderScript::IShaderScript(string path)
	: _shaderPath("scripts" + path), _shaderType(T)
{
	_isTypeKnown = true;
	_shaderId = glCreateShader(T);
}

IShaderScript::IShaderScript(string path, GLenum type)
	: _shaderPath("scripts/" + path), _shaderType(type)
{
	_isTypeKnown = true;
	_shaderId = glCreateShader(type);
}

IShaderScript::~IShaderScript()
{
}

void IShaderScript::cleanUp()
{
	_isLoaded = false;
	_isCompiled = false;
	_isTypeKnown = false;

	glDeleteShader(_shaderId);
}

string IShaderScript::readFile(string path)
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

string IShaderScript::readFile() 
{
	return readFile(_shaderPath);
}
