#pragma once
#ifndef __MODEL_TEXTURE_H_
#define __MODEL_TEXTURE_H_
#include "utility/common.hpp"
#include "ITexture.h"

namespace GameEngineM
{

	namespace ModelM
	{

		class ModelTexture : public TextureM::ITexture
		{
		public:
			ModelTexture();
			~ModelTexture();
		};

	}
}
#endif /* __MODEL_TEXTURE_H_ */