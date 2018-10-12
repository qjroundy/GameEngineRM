#pragma once

#ifndef	  __LIVING_H
#define	  __LIVING_H

#include "utility/common.hpp"
#include "ILiving.h"

namespace GameEngineM
{

	class Living : public ILiving
	{
	public:
		Living();
		~Living();
	};

}
#endif /* __LIVING_H */
