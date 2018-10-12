#include "TerrainShader.h"



TerrainShader::TerrainShader(string name)
	: ShaderProgram( new ShaderScript{name.append("VertexShader.glsl"), GL_VERTEX_SHADER}, new ShaderScript{name.append("FragmentShader.glsl"), GL_FRAGMENT_SHADER})
{
}

TerrainShader::~TerrainShader()
{
}