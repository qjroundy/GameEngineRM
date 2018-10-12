#pragma once

#ifndef	  __I_PLAYER_H
#define	  __I_PLAYER_H

#include "utility/common.hpp"
#include "IEntity.h"

class IPlayer : public IEntity
{
public:
	IPlayer();
	~IPlayer();
};

#endif /* __I_PLAYER_H */