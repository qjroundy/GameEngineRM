#pragma once

#ifndef   __ENTITY_ANIMAL_H_
#define	  __ENTITY_ANIMAL_H_

#include "utility/common.hpp"
#include "Entity.h"
#include "Animal.h"



	class EnityAnimal : public Entity, Animal
	{
	public:
		EnityAnimal();
		~EnityAnimal();
	};



#endif // __ENTITY_ANIMAL_H_