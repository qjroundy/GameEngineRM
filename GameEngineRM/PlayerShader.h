#pragma once
#include "IShaderProgram.h"
#ifndef __PLAYER_SHADER_H
#define __PLAYER_SHADER_H

namespace GameEngineM
{
	namespace ShaderM
	{
		class PlayerShader :
			public IShaderProgram
		{
		public:
			PlayerShader();
			~PlayerShader();
		};
	}
}
#endif /* __I_SHADER_PROGRAM_H */