#include "IShaderProgram.h"

namespace GameEngineM
{
	namespace ShaderM
	{
		IShaderProgram::IShaderProgram(ShaderScript vertexShader, ShaderScript fragmentShader)
		{
			_shaders.insert(make_pair(GL_VERTEX_SHADER, vertexShader));
			_shaders.insert(make_pair(GL_FRAGMENT_SHADER, fragmentShader));
			_programId = glCreateProgram();

#ifdef AUTOBUILD_SHADER
			vertexShader.loadSourceShader();
			vertexShader.compileShader();
			vertexShader.logErrors();

			fragmentShader.loadSourceShader();
			fragmentShader.compileShader();
			fragmentShader.logErrors();

			buildProgram();
#endif


		}

		//IShaderProgram::IShaderProgram()
		//{
		//	_programId = glCreateProgram();
		//}

		IShaderProgram::~IShaderProgram()
		{
			glDeleteProgram(_programId);
		}

		void IShaderProgram::buildProgram()
		{
			for (auto s : _shaders)
			{
				glAttachShader(_programId, s.second.getShaderId());
			}

			glLinkProgram(_programId);
			glValidateProgram(_programId);

		}

		void IShaderProgram::attachVertexShader(ShaderScript vertexShader)
		{
			_shaders.insert(make_pair(GL_VERTEX_SHADER, vertexShader));
		}

		void IShaderProgram::attachFragmentShader(ShaderScript fragmentShader)
		{
			_shaders.insert(make_pair(GL_FRAGMENT_SHADER, fragmentShader));

		}

		template<GLenum T>
		ShaderScript& IShaderProgram::getShaderScript()
		{
			return _shaders.at(T);
		}
		

		ShaderScript& IShaderProgram::getShaderScript(GLenum type)
		{
			return _shaders.at(type);
		}

		ShaderScript& IShaderProgram::operator[](GLenum type)
		{
			return _shaders.at(type);
		}

		void IShaderProgram::bindAttribute(GLuint attr, string name)
		{
			glBindAttribLocation(_programId, attr, name.c_str());
		}

		void IShaderProgram::start()
		{
			glUseProgram(_programId);
		}

		void IShaderProgram::stop()
		{
			glUseProgram(0);
		}

		void IShaderProgram::cleanUp()
		{
			
			for (auto s : _shaders)
			{
				glDetachShader(_programId, s.second.getShaderId());
				s.second.cleanUp();
			}

			glDeleteProgram(_programId);

		}

		template<GLenum T>
		void IShaderProgram::attachShader(ShaderScript shader)
		{
			_shaders.insert(make_pair(T, shader));
		}

		void IShaderProgram::attachShader(ShaderScript shader, GLenum shaderType)
		{
			_shaders.insert(make_pair(shaderType, shader));
		}

		GLuint IShaderProgram::getUniformLocation(string uniformName)
		{
			return glGetUniformLocation(_programId, uniformName.c_str());
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

		void IShaderProgram::loadVector(GLuint location, glm::vec3 value)
		{
			glUniform3f(location, value.x, value.y, value.z);
		}

		void IShaderProgram::loadVector(GLuint location, glm::vec3* value)
		{
			glUniform3f(location, value->x, value->y, value->z);
		}

		void IShaderProgram::loadMatrix(GLuint location, glm::mat4* value)
		{
			glUniformMatrix4fv(location, 1, GL_FALSE, &(*value)[0][0]);
		}

		void loadMatrix(GLuint location, glm::mat4 value)
		{
			glUniformMatrix4fv(location, 1, GL_FALSE, &value[0][0]);
		}

		void IShaderProgram::addUniformName(string name)
		{
			//_locationNames->push_back(name);
		}

	}
}