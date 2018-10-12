#pragma once

#ifndef	  __PLAYER_H_
#define	  __PLAYER_H_

#include "utility/common.hpp"
#include "IPlayer.h"
#include "Entity.h"

namespace GameEngineM
{

	class Player : public IPlayer
	{
	public:
		Player();
		~Player();
	};

}
#endif /* __PLAYER_H_ */
