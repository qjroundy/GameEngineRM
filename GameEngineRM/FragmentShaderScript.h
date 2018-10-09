#pragma once

#ifndef __FRAGMENT_SHADER_SCRIPT_H
#define	__FRAGMENT_SHADER_SCRIPT_H

#include "utility/common.hpp"
#include "ShaderScript.h"

namespace GameEngineM {

	class FragmentShaderScript : public ShaderScript
	{
	public:
		FragmentShaderScript(string path);
		~FragmentShaderScript();
	};

}
#endif /* __FRAGMENT_SHADER_SCRIPT_H */
