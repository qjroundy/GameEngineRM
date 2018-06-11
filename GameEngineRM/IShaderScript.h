#pragma once
#ifndef __I_SHADER_SCRIPT_H
#define __I_SHADER_SCRIPT_H

#include "utility/common.hpp"
namespace GameEngineM
{
	namespace ShaderM
	{
		class IShaderScript
		{
		private:
		protected:
			bool _isCompiled = false;
			bool _isLoaded = false;
			bool _isTypeKnown = false;
			bool _isSaved = false;
			GLuint _shaderId = 0;
			GLchar * _shaderData{};
			string _shaderPath = "";
			GLenum _shaderType = 0;

			string readFile(string path);
		public:
			IShaderScript() = default;

			inline bool getShaderId()	{ return _shaderId; }
			inline bool isCompiled()	{ return _isCompiled; }
			inline bool isTypeKnown()	{ return _isTypeKnown; }
			inline bool isLoaded()		{ return _isLoaded; }
			inline bool isSaved()		{ return _isSaved; }
			template<GLenum T>
			IShaderScript(string path);

			IShaderScript(string path, GLenum type);

			void cleanUp();
			string readFile();
			virtual void loadSourceShader() = 0;
			virtual void loadBinShader() = 0;
			virtual void compileShader() = 0;
			virtual void logErrors()=0;
			~IShaderScript();
		};
	}
}
#endif /* __I_SHADER_SCRIPT_H */