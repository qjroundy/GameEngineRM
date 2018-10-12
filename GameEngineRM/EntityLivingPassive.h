#pragma once

#ifndef	  __ENTITY_LIVING_PASSIVE_H_
#define	  __ENTITY_LIVING_PASSIVE_H_

#include "utility/common.hpp"
#include "Entity.h"
#include "Living.h"
#include "Passive.h"

namespace GameEngineM 
{

	class EntityLivingPassive : public Entity, Living, Passive
	{
	public:
		EntityLivingPassive();
		~EntityLivingPassive();
	};

}
#endif /* __ENTITY_LIVING_PASSIVE_H_ */
