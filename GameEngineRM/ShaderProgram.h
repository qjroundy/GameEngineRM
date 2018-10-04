#pragma once
#ifndef __SHADER_PROGRAM_H
#define __SHADER_PROGRAM_H
#include "utility/common.hpp"
#include "IShaderProgram.h"
#include "ShaderScript.h"
#include <map>

namespace GameEngineM {
	class ShaderProgram : public IShaderProgram
	{
	private:
		map<GLuint, string> _attributes;
		map<string, GLint> _uniforms_locations;

	public:
		void addUnifrom(string name);
		void addUniformName(string name);
		ShaderProgram() = default;
		ShaderProgram(ShaderScript vertexShader, ShaderScript fragmentShader);
		ShaderProgram(map<GLenum, ShaderScript> shaders);
		inline void loadUniform(string name, GLfloat value)			override { loadUniform(_uniforms_locations[name], value); };
		inline void loadUniform(string name, GLint value)			override { loadUniform(_uniforms_locations[name], value); };
		inline void loadUniform(string name, GLboolean value)		override { loadUniform(_uniforms_locations[name], value); };
		inline void loadUniform(string name, vec3 value)			override { loadUniform(_uniforms_locations[name], value); };
		inline void loadUniform(string name, vec4 value)			override { loadUniform(_uniforms_locations[name], value); };
		inline void loadUniform(string name, mat4 value)			override { loadUniform(_uniforms_locations[name], value); };
		inline void loadUniform(GLuint location, GLfloat value)		override { loadFloat(location, value); };
		inline void loadUniform(GLuint location, GLint value)		override { loadInt(location, value); };
		inline void loadUniform(GLuint location, GLboolean value)	override { loadInt(location, value); };
		inline void loadUniform(GLuint location, vec3 value)		override { loadVector3f(location, value); };
		inline void loadUniform(GLuint location, vec4 value)		override { loadVector4f(location, value); };
		inline void loadUniform(GLuint location, mat4 value)		override { loadMatrix4f(location, value); };
		~ShaderProgram();
		void addAttribute(GLuint idx, string attribName) override;
		void addAttribute(string attribName) override;
		void getAllUniformLocations() override;
		void bindAttributes() override;
	};
}
#endif __SHADER_PROGRAM_H