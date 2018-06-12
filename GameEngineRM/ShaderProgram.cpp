#include "ShaderProgram.h"

using namespace GameEngineM::ShaderM;

ShaderProgram::ShaderProgram(ShaderScript vertexShader, ShaderScript fragmentShader)
	: IShaderProgram(vertexShader,fragmentShader)
{
}

ShaderProgram::ShaderProgram(map<GLenum, ShaderScript> shaders)
	: IShaderProgram(shaders)
{
}


ShaderProgram::~ShaderProgram()
{
}

void ShaderProgram::addAttribute(GLuint idx, string attribName)
{
	_attributes[idx] = attribName;
}

void ShaderProgram::addAttribute(string attribName)
{
	static GLuint attribCount = 0;
	_attributes[attribCount++] = attribName;
}

void ShaderProgram::getAllUniformLocations()
{
	for (auto u : _uniforms_locations)
	{
		u.second = getUniformLocation(u.first);
	}
}

void ShaderProgram::bindAttributes()
{
	for (auto a : _attributes)
	{
		bindAttribute(a.first, a.second);
	}
}