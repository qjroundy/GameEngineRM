#pragma once
#ifndef __SHADER_SCRIPT_H_
#define __SHADER_SCRIPT_H_

#include "IShaderProgram.h"
namespace GameEngineM
{
	class TerrainShader :
		public IShaderProgram
	{
	public:
		TerrainShader() = delete;
		TerrainShader(string name);

		~TerrainShader();
	};
}
#endif /* __SHADER_SCRIPT_H_ */