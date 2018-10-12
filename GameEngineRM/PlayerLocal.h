#pragma once

#ifndef	  __PLAYER_LOCAL_H_
#define	  __PLAYER_LOCAL_H_

#include "utility/common.hpp"
#include "Player.h"
#include "LocalConnection.h"



	class PlayerLocal : public Player, public LocalConnection
	{
	public:
		PlayerLocal();
		~PlayerLocal();
	};


#endif /* __PLAYER_LOCAL_H_ */
