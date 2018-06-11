#include "IShaderProgram.h"
#include <algorithm>
namespace GameEngineM
{
	namespace ShaderM
	{
		IShaderProgram::IShaderProgram(ShaderScript vertexShader, ShaderScript fragmentShader)
			: _programId(glCreateProgram())
		{

			_shaders.insert(make_pair(GL_VERTEX_SHADER, vertexShader));
			_shaders.insert(make_pair(GL_FRAGMENT_SHADER, fragmentShader));

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

		IShaderProgram::IShaderProgram(std::map<GLenum,ShaderScript> shaders)
			: _programId(glCreateProgram())
		{
			_shaders.insert(shaders.begin(), shaders.end());
		}

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

			glProgramParameteri(_programId, GL_PROGRAM_BINARY_RETRIEVABLE_HINT, GL_TRUE);
			glLinkProgram(_programId);
			glValidateProgram(_programId);
			
			GLint binaryLength=0;

			glGetProgramiv(_programId, GL_PROGRAM_BINARY_LENGTH, &binaryLength);
			if (binaryLength > 0)
			{

				GLint formats = 0;

				glGetIntegerv(GL_NUM_PROGRAM_BINARY_FORMATS, &formats);
				GLint* binaryFormats=new GLint[formats];
				glGetIntegerv(GL_PROGRAM_BINARY_FORMATS, binaryFormats);
				u8 * binary = new u8[binaryLength];
				glGetProgramBinary(_programId, binaryLength, NULL, (GLenum*)binaryFormats, binary);

				FILE* fp = fopen(("shader_" + to_string(_programId) + ".bin").c_str(), "wb");
				fwrite(binary, binaryLength, 1, fp);
				fclose(fp);
				delete binary;
				debugInfo("Shader cached successfully");
			}
			else
			{
				debugLog("Shader failed to cache");
			}

		}

		void IShaderProgram::attachVertexShader(ShaderScript vertexShader)
		{
			_shaders[GL_VERTEX_SHADER] = vertexShader;
		}

		void IShaderProgram::attachFragmentShader(ShaderScript fragmentShader)
		{
			_shaders[GL_FRAGMENT_SHADER] = fragmentShader;

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
			_shaders[T] = shader;
		}

		void IShaderProgram::attachShader(ShaderScript shader, GLenum shaderType)
		{
			_shaders[shaderType] = shader;
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