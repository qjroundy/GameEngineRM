#pragma once
#ifndef __SHADER_SCRIPT_H_
#define __SHADER_SCRIPT_H_

#include "ShaderProgram.h"

class TerrainShader :
		public ShaderProgram
	{
	public:
		TerrainShader() = delete;
		TerrainShader(string name);

		~TerrainShader();
	};

#endif /* __SHADER_SCRIPT_H_ */