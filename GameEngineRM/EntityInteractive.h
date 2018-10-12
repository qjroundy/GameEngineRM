#pragma once

#ifndef __ENTITY_INTERACTIVE_H_
#define __ENTITY_INTERACTIVE_H_

#include "utility/common.hpp"
#include "Entity.h"
#include "Interactive.h"



	class EntityInteractive : public Entity, Interactive
	{
	public:
		EntityInteractive();
		~EntityInteractive();
	};



#endif // !__ENTITY_INTERACTIVE_H_