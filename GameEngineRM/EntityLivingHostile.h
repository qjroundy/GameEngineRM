#pragma once

#ifndef	  __ENTITY_LIVING_HOSTILE_H
#define	  __ENTITY_LIVING_HOSTILE_H

#include "utility/common.hpp"
#include "Entity.h"
#include "Living.h"
#include "Hostile.h"



	class EntityLivingHostile : public Entity, public Living, public Hostile
	{
	public:
		EntityLivingHostile();
		~EntityLivingHostile();
	};


#endif /* __ENTITY_LIVING_HOSTILE_H */
