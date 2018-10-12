#pragma once

#ifndef	  __TERRAIN_RENDERER_H_
#define	  __TERRAIN_RENDERER_H_

#include "utility/common.hpp"
#include "Renderer.h"

namespace GameEngineM
{

	class TerrainRenderer : public Renderer
	{
	public:
		TerrainRenderer();
		~TerrainRenderer();
	};

}
#endif /* __TERRAIN_RENDERER_H_ */
