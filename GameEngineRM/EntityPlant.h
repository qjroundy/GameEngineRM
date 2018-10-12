#pragma once

#ifndef __ENTITY_PLANT_H_
#define __ENTITY_PLANT_H_

#include "utility/common.hpp"
#include "Entity.h"
#include "Plant.h"



	class EntityPlant : public Entity, Plant
	{
	public:
		EntityPlant();
		~EntityPlant();
	};



#endif // !__ENTITY_PLANT_H_