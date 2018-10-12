#pragma once

#ifndef	  __ENITTY_NONLIVING_H_
#define	  __ENITTY_NONLIVING_H_

#include "utility/common.hpp"
#include "NonLiving.h"
#include "Entity.h"

class EntityNonLiving : public Entity, public NonLiving
{
public:
	EntityNonLiving();
	~EntityNonLiving();
};

#endif /* __ENITTY_NONLIVING_H_ */
