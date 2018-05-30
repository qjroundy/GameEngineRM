#include "ShaderScript.h"

namespace GameEngineM
{
	namespace ShaderM
	{
		void ShaderScript::compileShader()
		{
			if (!_isCompiled)
			{
				debugMessage("Compiling shader.");
			glShaderSource(_shaderId, 1, &_shaderData, NULL);
			glCompileShader(_shaderId);
			_isCompiled = true;
			}
		}

		void ShaderScript::loadSourceShader()
		{
			if (!_isLoaded)
			{
				debugMessage("Loading shader source");
				string fsrc = readFile();
				_shaderData = fsrc.c_str();
				_isLoaded = true;
			}
			return;
		}

		void ShaderScript::loadBinShader()
		{
			//glShaderBinary(1,&_shaderType,); //incomplete...
		}

		void ShaderScript::logErrors()
		{
			if (_isLoaded && _isCompiled)
			{
				GLint result = GL_FALSE;
				int logLength = 0;

				// Check vertex shader
				glGetShaderiv(_shaderId, GL_COMPILE_STATUS, &result);
				glGetShaderiv(_shaderId, GL_INFO_LOG_LENGTH, &logLength);
				std::vector<char> shaderError((logLength > 1) ? logLength : 1);
				glGetShaderInfoLog(_shaderId, logLength, NULL, &shaderError[0]);
				//CONSOLE(shaderError.data);
			}
		}

		template<GLenum T>
		ShaderScript::ShaderScript(string pathToSource)
			: IShaderScript(pathToSource)
		{
		}

		ShaderScript::ShaderScript(string path, GLenum type)
			: IShaderScript(path,type)
		{

		}

		ShaderScript::~ShaderScript()
		{
		}
	}
}