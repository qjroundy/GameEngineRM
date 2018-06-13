#pragma once
#ifndef	  __MODEL_TEXTURE_H_
#define	  __MODEL_TEXTURE_H_

#include "ITexture.h"

namespace GameEngineM
{

	class ModelTexture :
		public ITexture
	{
	public:
		ModelTexture();
		~ModelTexture();
	};

}
#endif /* __MODEL_TEXTURE_H_ */
