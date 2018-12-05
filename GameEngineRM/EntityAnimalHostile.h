#pragma once

#ifndef __ENTITY_ANIMAL_HOSTILE_H_
#define __ENTITY_ANIMAL_HOSTILE_H_

#include "utility/common.hpp"
#include "EntityAnimal.h"
#include "Hostile.h"

class EntityAnimalHostile : public EntityAnimal, Hostile
{
public:
	EntityAnimalHostile();
	~EntityAnimalHostile();
};

#endif // !__ENTITY_ANIMAL_HOSTILE_H_