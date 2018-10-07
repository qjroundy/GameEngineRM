#include "IShaderProgram.h"
#include <algorithm>

using namespace GameEngineM;

IShaderProgram::~IShaderProgram()
{
}

void IShaderProgram::loadFloat(GLuint location, GLfloat value)
{
	glUniform1f(location, value);
}

void IShaderProgram::loadInt(GLuint location, GLint value)
{
	glUniform1i(location, value);
}
void IShaderProgram::loadBool(GLuint location, GLboolean value)
{
	glUniform1i(location, (value) ? GL_TRUE : GL_FALSE);
}

void IShaderProgram::loadVector3f(GLuint location, glm::vec3 value)
{
	glUniform3f(location, value.x, value.y, value.z);
}

void IShaderProgram::loadVector4f(GLuint location, vec4 value)
{
	glUniform4f(location, value.x, value.y, value.z, value.w);
}

void IShaderProgram::loadMatrix4f(GLuint location, glm::mat4 value)
{
	glUniformMatrix4fv(location, 1, GL_FALSE, &(value)[0][0]);
}

void loadMatrix(GLuint location, glm::mat4 value)
{
	glUniformMatrix4fv(location, 1, GL_FALSE, &value[0][0]);
}

