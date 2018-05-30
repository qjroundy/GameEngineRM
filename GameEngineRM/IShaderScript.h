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
			const char * _shaderData = NULL;
			string _shaderPath = "";
			GLenum _shaderType = 0;

			string readFile(string path);
		public:
			IShaderScript() = default;

			inline const bool getShaderId() const noexcept { return _shaderId; }
			inline const bool isCompiled() const noexcept { return _isCompiled; }
			inline const bool isTypeKnown() const noexcept { return _isTypeKnown; }
			inline const bool isLoaded() const noexcept { return _isLoaded; }
			inline const bool isSaved() const noexcept { return _isSaved; }
			template<GLenum T>
			IShaderScript(string path);

			IShaderScript(string path, GLenum type);

			void cleanUp();
			string readFile();
			virtual void loadSourceShader() = 0;
			virtual void loadBinShader() = 0;
			virtual void compileShader() = 0;
			virtual void logErrors() = 0;
			~IShaderScript();
		};
	}
}
#endif /* __I_SHADER_SCRIPT_H */