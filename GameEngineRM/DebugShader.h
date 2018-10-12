#pragma once

#ifndef	  __DEBUG_SHADER_H_
#define	  __DEBUG_SHADER_H_

#include "utility/common.hpp"
#include "ShaderProgram.h"

namespace GameEngineM
{

	class DebugShader : public ShaderProgram
	{
	public:
		DebugShader();
		~DebugShader();
	};

}
#endif /* __DEBUG_SHADER_H_ */
