#include "PlayerRenderer.h"



PlayerRenderer::PlayerRenderer()
{
}


PlayerRenderer::~PlayerRenderer()
{
}

void PlayerRenderer::start()
{
	glUseProgram(getShaderProgram().programId);

}
void PlayerRenderer::stop()
{

}

void PlayerRenderer::init()
{

}void PlayerRenderer::render(ModelTexturedMesh playerModel)
{
	// set PlayerModel to VBO/VBA and start draw call
}