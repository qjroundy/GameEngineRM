#pragma once
#ifndef __I_RENDERER_H_
#define __I_RENDERER_H_

#include "utility/common.hpp"
#include "IShaderProgram.h"


class IRenderer
{

public:
	IRenderer() = default;
	~IRenderer();

	virtual void init() = 0;
	virtual void start() = 0;
	virtual void render() = 0;
	virtual void stop() = 0;
	virtual void cleanup();

	virtual void setShaderProgram(unique_ptr<IShaderProgram> shaderProgram) = 0;
	virtual const IShaderProgram& getShaderProgram(void) = 0;
	virtual void changeShaderProgram(unique_ptr<IShaderProgram> shaderProgram) = 0;
};

#endif /* __I_RENDERER_H_ */