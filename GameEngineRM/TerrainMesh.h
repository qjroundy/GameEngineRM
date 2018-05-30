#pragma once
#ifndef __I_TERRAIN_MESH_H_
#define __I_TERRAIN_MESH_H_

#include "utility/common.hpp"
#include "IMesh.h"

namespace GameEngineM
{
	namespace TerrainM
	{

		class TerrainMesh :
			public MeshM::IMesh
		{
		public:
			TerrainMesh();
			~TerrainMesh();
		};

	}
}
#endif /* __I_TERRAIN_MESH_H_ */