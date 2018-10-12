#pragma once

#ifndef	  __HOSTILE_H
#define	  __HOSTILE_H

#include "utility/common.hpp"
#include "IHostile.h"

namespace GameEngineM
{

	class Hostile : public IHostile
	{
	public:
		Hostile();
		~Hostile();
	};

}
#endif /* __HOSTILE_H */
