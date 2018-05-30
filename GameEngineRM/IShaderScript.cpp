#include "IShaderScript.h"

namespace GameEngineM
{
	namespace ShaderM
	{
		template<GLenum T>
		IShaderScript::IShaderScript(string path)
			: _shaderPath(path), _shaderType(T)
		{
			_isTypeKnown = true;
		}

		IShaderScript::IShaderScript(string path, GLenum type)
			: _shaderPath(path), _shaderType(type)
		{
			_isTypeKnown = true;
		}

		IShaderScript::~IShaderScript()
		{
		}

		void IShaderScript::cleanUp()
		{
			_isLoaded = false;
			_isCompiled = false;
			_isTypeKnown = false;

			glDeleteShader(_shaderId);
		}

		void IShaderScript::compileShader()
		{

			_isCompiled = true;
		}

		string IShaderScript::readFile(string path)
		{
			string content;
			ifstream fileStream{ path, ios::in };

			if (!fileStream.is_open()) {
				cerr << "Could not read file " << path << ". File does not exist." << nl;
				return "";
			}

			string line = "";
			while (!fileStream.eof()) {
				getline(fileStream, line);
				content.append(line + "\n");
			}

			fileStream.close();
			_isLoaded = true;
			return content;
		}

		string IShaderScript::readFile() {
			return readFile(_shaderPath);
		}
	}
}