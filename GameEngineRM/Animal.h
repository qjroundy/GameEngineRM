#pragma once

#ifndef	  __ANIMAL_H
#define	  __ANIMAL_H

#include "utility/common.hpp"
#include "IAnimal.h"
#include "Living.h"

class Animal : public IAnimal, Living
{

public:
	Animal();
	~Animal();
	int _species;
	int _breed;
};

#endif // __ANIMAL_H
