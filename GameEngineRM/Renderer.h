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
	void start() override { glUseProgram(_shaderProgram->programId()); };
	void stop() override { glUseProgram(NULL); };
	void init() override {};
	virtual void render() = 0;
	void setShaderProgram(unique_ptr<IShaderProgram> shaderProgram) override;
	const IShaderProgram& getShaderProgram(void) override;
	void changeShaderProgram(unique_ptr<IShaderProgram> shaderProgram) override;

	Renderer() = default;
	Renderer(unique_ptr<IShaderProgram> shaderProgram);
	~Renderer();
};

#endif /* __RENDERER_H_ */