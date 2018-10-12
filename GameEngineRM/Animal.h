#pragma once

#ifndef	  __ANIMAL_H
#define	  __ANIMAL_H

#include "utility/common.hpp"
#include "IAnimal.h"

class Animal : public IAnimal
{
public:
	Animal();
	~Animal();
};

#endif // __ANIMAL_H
