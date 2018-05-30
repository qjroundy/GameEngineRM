#include "TerrainShader.h"

namespace GameEngineM
{
	namespace ShaderM
	{

		TerrainShader::TerrainShader(string name)
			: IShaderProgram( ShaderScript{name.append("VertexShader.glsl"), GL_VERTEX_SHADER}, ShaderScript{name.append("FragmentShader.glsl"), GL_FRAGMENT_SHADER})
		{
		}


		TerrainShader::~TerrainShader()
		{
		}

	}
}