#pragma once

#ifndef	  __LIVING_H
#define	  __LIVING_H

#include "utility/common.hpp"
#include "ILiving.h"

class Living : public ILiving
{
public:
	int currentHealth;
	int maxHealth;
	Living();
	~Living();
};

#endif /* __LIVING_H */
