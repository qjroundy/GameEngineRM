#pragma once

#ifndef	  __PLAYER_REMOTE_H_
#define	  __PLAYER_REMOTE_H_

#include "utility/common.hpp"
#include "Player.h"
#include "RemoteConnection.h"



	class PlayerRemote : public Player, public RemoteConnection
	{
	public:
		PlayerRemote();
		~PlayerRemote();
	};


#endif /* __PLAYER_REMOTE_H_ */
