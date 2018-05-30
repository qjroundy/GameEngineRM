#pragma once
#ifndef __I_TERRAIN_H_
#define __I_TERRAIN_H_

#include "utility/common.hpp"
#include "TerrainMesh.h"
#include "TerrainTexture.h"

namespace GameEngineM
{
	namespace TerrainM
	{

		class ITerrain
		{
			TerrainMesh _mesh;
			TerrainTexture _texture;

		public:
			ITerrain();
			~ITerrain();
		};

	}
}
#endif /* __I_TERRAIN_H_ */