#pragma once

#ifndef __I_HAS_AI_H_
#define __I_HAS_AI_H_

#include "utility/common.hpp"
#include "IEntity.h"

class IHasAI
{
public:
	virtual void doAI(IEntity target) = 0;

	IHasAI();
	~IHasAI();
};

#endif // !__I_HAS_AI_H_
