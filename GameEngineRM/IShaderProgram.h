#pragma once
#ifndef __I_SHADER_PROGRAM_H
#define __I_SHADER_PROGRAM_H

#include "ShaderScript.h"
#include <map>

namespace GameEngineM
{
	class IShaderProgram
	{
	private:
		ShaderScript _vertexShader{};
		ShaderScript _fragmentShader{};


	protected:
		map<GLenum, ShaderScript> _shaders;
		map<string, GLint> _uniforms_locations;
		GLuint _programId;
	public:
		virtual void bindAttributes() = 0;
		virtual void getAllUniformLocations() = 0;
		virtual void addAttribute(string attribName) = 0;
		virtual void addAttribute(GLuint idx, string attribName) = 0;
		GLuint getUniformLocation(string uniformName);
		void generateShaderProgram();
		inline const  GLuint programId() { return _programId; }
		void load();
		void addUnifrom(string name);

		IShaderProgram(std::map<GLenum, ShaderScript> shaders);
		void buildProgram();
		IShaderProgram() = default;
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

		template<typename T> void updateUniform(GLuint location, T value) { loadUniform(location, value); };
		template<typename T> void updateUniform(string name, T value) { loadUniform(name, value); };

		void loadUniform(GLuint location, GLfloat value) { loadFloat(location, value); };
		void loadUniform(GLuint location, GLint value) { loadInt(location, value); };
		void loadUniform(GLuint location, GLboolean value) { loadInt(location, value); };
		void loadUniform(GLuint location, vec3 value) { loadVector3f(location, value); };
		void loadUniform(GLuint location, vec4 value) { loadVector4f(location, value); };
		void loadUniform(GLuint location, mat4 value) { loadMatrix4f(location, value); };

		void loadUniform(string name, GLfloat value) { loadUniform(_uniforms_locations[name], value); };
		void loadUniform(string name, GLint value) { loadUniform(_uniforms_locations[name], value); };
		void loadUniform(string name, GLboolean value) { loadUniform(_uniforms_locations[name], value); };
		void loadUniform(string name, vec3 value) { loadUniform(_uniforms_locations[name], value); };
		void loadUniform(string name, vec4 value) { loadUniform(_uniforms_locations[name], value); };
		void loadUniform(string name, mat4 value) { loadUniform(_uniforms_locations[name], value); };

		void loadFloat(GLuint location, GLfloat value);
		void loadInt(GLuint location, GLint value);
		void loadBool(GLuint location, GLboolean value);
		void loadVector3f(GLuint location, vec3 value);
		void loadVector4f(GLuint location, vec4 value);
		void loadMatrix4f(GLuint location, mat4 value);

		void addUniformName(string name);

	};
}
#endif /* __I_SHADER_PROGRAM_H */