#include "PlayerShader.h"
#include "VertexShaderScript.h"
#include "FragmentShaderScript.h"
#include "utility/common.hpp"

PlayerShader::PlayerShader()
{
	attachShader(new VertexShaderScript("scripts/PlayerVertexShader.glsl"), GL_VERTEX_SHADER);
	attachShader(new FragmentShaderScript("scripts/PlayerFragmentShader.glsl"), GL_FRAGMENT_SHADER);
	setName("PlayerShader");
}

PlayerShader::~PlayerShader()
{
}

void PlayerShader::setName(string name)
{
	this->_name = name;
}

string &  PlayerShader::getName()
{
	return _name;
}