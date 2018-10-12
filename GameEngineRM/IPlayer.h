#pragma once

#ifndef	  __I_PLAYER_H
#define	  __I_PLAYER_H

#include "utility/common.hpp"
#include "IEntity.h"

namespace GameEngineM
{

	class IPlayer : public IEntity, IPlayer
	{
	public:
		IPlayer();
		~IPlayer();
	};

}
#endif /* __I_PLAYER_H */
