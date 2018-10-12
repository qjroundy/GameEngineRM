#pragma once

#ifndef __PLAYER_RENDERER_H
#define __PLAYER_RENDERER_H

#include "utility/common.hpp"
#include "Renderer.h"
#include "ModelTexturedMesh.h"

namespace GameEngineM
{

	class PlayerRenderer : public Renderer
	{
	public:
		PlayerRenderer();
		~PlayerRenderer();

		virtual void start() override;
		virtual void stop() override;
		virtual void init() override;
		virtual void render() override;

		//void addPlayer(IPlayer player);
		void setTexturedMesh_firstPerson(ModelTexturedMesh playerModel);
		void setTexturedMesh_thirdPerson(ModelTexturedMesh playerModel);
	};


}
#endif /* __PLAYER_RENDERER_H */
