#pragma once

#ifndef __I_CAN_RENDER_H_
#define __I_CAN_REDNER_H_

#include "utility/common.hpp"

class ICanRender
	{
	public:
		virtual void doDraw() = 0;

		ICanRender();
		~ICanRender();
	};


#endif // !__I_CAN_RENDER_H_
