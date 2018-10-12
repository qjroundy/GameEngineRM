#pragma once

#ifndef	  __ENTITY_LIVING_NEUTRAL_H_
#define	  __ENTITY_LIVING_NEUTRAL_H_

#include "utility/common.hpp"
#include "Entity.h"
#include "Living.h"
#include "Neutral.h"

namespace GameEngineM
{

	class EntityLivingNeutral : public Entity, Living, Neutral
	{
	public:
		EntityLivingNeutral();
		~EntityLivingNeutral();
	};

}
#endif /* __ENTITY_LIVING_NEUTRAL_H_ */
