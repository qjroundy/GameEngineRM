#pragma once

#include "utility/common.hpp"
#include "ShaderProgram.h"

#ifndef __PLAYER_SHADER_H
#define __PLAYER_SHADER_H

class PlayerShader :
	public ShaderProgram
{
private:
	std::string _name;
public:
	PlayerShader();
	~PlayerShader();

	void setName(string name) override;
	string & getName() override;
};

#endif /* __I_SHADER_PROGRAM_H */