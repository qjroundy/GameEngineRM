#pragma once

#ifndef	  __VERTEX_SHADER_SCRIPT_H
#define	  __VERTEX_SHADER_SCRIPT_H

#include "utility/common.hpp"
#include "ShaderScript.h"

class VertexShaderScript : public ShaderScript
{
public:
	VertexShaderScript(string path);
	~VertexShaderScript();
};

#endif /* __VERTEX_SHADER_SCRIPT_H */
