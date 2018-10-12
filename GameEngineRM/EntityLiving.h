#pragma once

#ifndef	  __ENTITY_LIVING_H_
#define	  __ENTITY_LIVING_H_

#include "utility/common.hpp"
#include "Living.h"
#include "Entity.h"

namespace GameEngineM
{

	class EntityLiving : public Entity, public Living
	{
	public:
		EntityLiving();
		~EntityLiving();
	};

}
#endif /* __ENTITY_LIVING_H_ */
