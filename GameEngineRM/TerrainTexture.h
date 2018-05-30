#pragma once
#ifndef __TERRAIN_TEXTURE_H_
#define __TERRAIN_TEXTURE_H_

#include "utility/common.hpp"
#include "ITexture.h"

namespace GameEngineM
{
	namespace TerrainM
	{

		class TerrainTexture : public TextureM::ITexture
		{
		public:
			TerrainTexture();
			~TerrainTexture();
		};

	}
}
#endif /* __TERRAIN_TEXTURE_H_ */