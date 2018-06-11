#pragma once
#ifndef __I_SHADER_PROGRAM_H
#define __I_SHADER_PROGRAM_H

#include "ShaderScript.h"
#include "IShaderScript.h"
#include <vector>
#include <map>

namespace GameEngineM
{
	namespace ShaderM
	{
		class IShaderProgram
		{
		private:
			ShaderScript _vertexShader{};
			ShaderScript _fragmentShader{};
			map<GLenum, ShaderScript> _shaders;

		protected:
			GLuint _programId;
		public:
			IShaderProgram(std::map<GLenum,ShaderScript> shaders);
			void buildProgram();
			IShaderProgram() = delete;
			IShaderProgram(ShaderScript vertexShader, ShaderScript fragmentShader);
			~IShaderProgram();
			ShaderScript& operator[](GLenum type);

			template<GLenum T> ShaderScript& getShaderScript();
			template<GLenum T> void attachShader(ShaderScript);

			void attachShader(ShaderScript, GLenum);
			ShaderScript& getShaderScript(GLenum type);

			void attachVertexShader(ShaderScript vertexShader);
			void attachFragmentShader(ShaderScript fragmentShader);

			void start();
			void stop();
			void cleanUp();
			void bindAttribute(GLuint attr, string name);
			GLuint getUniformLocation(string uniformName);
			void loadFloat(GLuint location, GLfloat value);
			void loadInt(GLuint location, GLint value);
			void loadBool(GLuint location, GLboolean value);
			void loadVector(GLuint location, glm::vec3 value);
			void loadVector(GLuint location, glm::vec3* value);
			void loadMatrix(GLuint location, glm::mat4* value);
			void loadMatrix(GLuint location, glm::mat4 value);
			void addUniformName(string name);

		};

	}
}
#endif /* __I_SHADER_PROGRAM_H */