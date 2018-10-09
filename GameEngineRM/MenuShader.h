#pragma once
#ifndef __MENU_SHADER_H
#define __MENU_SHADER_H

#include "utility/common.hpp"
#include "ShaderProgram.h"

namespace GameEngineM
{

	class MenuShader : public ShaderProgram
	{
	public:
		MenuShader();
		~MenuShader();
	};

#endif /* __MENU_SHADER_H */
}