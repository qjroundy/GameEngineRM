#pragma once

#ifndef	  __DEBUG_RENDERER_H_
#define	  __DEBUG_RENDERER_H_

#include "utility/common.hpp"
#include "Renderer.h"

namespace GameEngineM
{

	class DebugRenderer  : public Renderer
	{
	public:
		DebugRenderer();
		~DebugRenderer();
	};

}
#endif /* __DEBUG_RENDERER_H_ */
