#pragma once

#ifndef	  __I_REMOTE_PLAYER_H_
#define	  __I_REMOTE_PLAYER_H_

#include "utility/common.hpp"
#include "IPlayer.h"

namespace GameEngineM
{

	class IRemotePlayer : public IPlayer
	{
	public:
		IRemotePlayer();
		~IRemotePlayer();
	};

}
#endif /* __I_REMOTE_PLAYER_H_ */
