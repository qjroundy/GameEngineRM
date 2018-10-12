#pragma once

#ifndef	  __REMOTE_CONNECTION_H
#define	  __REMOTE_CONNECTION_H

#include "utility/common.hpp"
#include "Connection.h"

namespace GameEngineM
{

	class RemoteConnection : public Connection
	{
	public:
		RemoteConnection();
		~RemoteConnection();
	};

}
#endif /* __REMOTE_CONNECTION_H */
