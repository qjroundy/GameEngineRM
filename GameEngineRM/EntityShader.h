#pragma once
#ifndef __ENTITY_SHADER_H
#define __ENTITY_SHADER_H
#include "IShaderProgram.h"

namespace GameEngineM
{

	class EntityShader :
		public IShaderProgram
	{
	public:
		EntityShader();
		~EntityShader();
	};
}

#endif /* __ENTITY_SHADER_H */