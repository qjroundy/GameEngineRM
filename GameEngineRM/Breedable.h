#pragma once

#ifndef __BREEDABLE_H_
#define __BREEDABLE_H_

#include "utility/common.hpp"
#include "IBreedable.h"

class Breedable :
	public IBreedable
{
public:
	Breedable();
	~Breedable();
};

#endif // !__BREEDABLE_H_
