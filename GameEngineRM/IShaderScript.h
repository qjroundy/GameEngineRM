#pragma once
#ifndef __I_SHADER_SCRIPT_H
#define __I_SHADER_SCRIPT_H

#include "utility/common.hpp"
class IShaderScript
	{
private:
protected:
	//bool _isCompiled = false;

	virtual string readFile(string path) = 0;
public:
	IShaderScript() = default;

	inline virtual const bool isCompiled() = 0;
	inline virtual const bool isLoaded() = 0;
	inline virtual const bool isTypeKnown() = 0;
	inline virtual const bool isSaved() = 0;
	inline virtual const GLuint shaderId() = 0;
	inline virtual const GLuint getShaderId() = 0;

	virtual void cleanUp()=0;
	virtual string readFile() = 0;
	virtual void loadSourceShader() = 0;
	virtual void loadBinShader() = 0;
	virtual void compileShader() = 0;
	virtual void logErrors() = 0;
	~IShaderScript();
};

#endif /* __I_SHADER_SCRIPT_H */