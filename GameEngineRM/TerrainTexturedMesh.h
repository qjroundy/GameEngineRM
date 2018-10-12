#pragma once
#ifndef	  __TERRAIN_TEXTURED_MODEL_H
#define	  __TERRAIN_TEXTURED_MODEL_H

#include "TerrainTexture.h"
#include "TerrainMesh.h"
#include "ITerrain.h"



	class TerrainTexturedMesh :
		public TerrainTexture,
		public TerrainMesh,
		public ITerrain
	{
	public:
		TerrainTexturedMesh();
		~TerrainTexturedMesh();
	};


#endif /* __TERRAIN_TEXTURED_MODEL_H */
