#pragma once

#ifndef	  __LOCAL_CONNECTION_H_
#define	  __LOCAL_CONNECTION_H_

#include "utility/common.hpp"
#include "Connection.h"

namespace GameEngineM
{

	class LocalConnection : public Connection
	{
	public:
		LocalConnection();
		~LocalConnection();
	};

}
#endif /* __LOCAL_CONNECTION_H_ */
