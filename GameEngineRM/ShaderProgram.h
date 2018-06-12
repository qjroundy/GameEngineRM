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

	public:
		ShaderProgram() = default;
		ShaderProgram(ShaderScript vertexShader, ShaderScript fragmentShader);
		ShaderProgram(map<GLenum, ShaderScript> shaders);

		~ShaderProgram();
		void addAttribute(GLuint idx, string attribName) override;
		void addAttribute(string attribName) override;
		void getAllUniformLocations() override;
		void bindAttributes() override;
	};
}
#endif __SHADER_PROGRAM_H