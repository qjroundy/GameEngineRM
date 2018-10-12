#pragma once

#ifndef __RENDERER_H_
#define __RENDERER_H_

#include "utility/common.hpp"
#include "IRenderer.h"


class Renderer : public IRenderer
{
private:
	unique_ptr<IShaderProgram> _shaderProgram;

public:
	void start() override {};
	void stop() override {};
	void init() override {};
	void render() override {};
	void setShaderProgram(unique_ptr<IShaderProgram> shaderProgram) override;
	const IShaderProgram& getShaderProgram(void) override;
	void changeShaderProgram(unique_ptr<IShaderProgram> shaderProgram) override;

	Renderer() = default;
	Renderer(unique_ptr<IShaderProgram> shaderProgram);
	~Renderer();
};

#endif /* __RENDERER_H_ */