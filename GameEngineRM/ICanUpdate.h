#pragma once

#ifndef   __I_CAN_UPDATE_H_
#define	  __I_CAN_UPDATE_H_

#include "utility/common.hpp"

class ICanUpdate
	{
	public:
		virtual void doUpdate() = 0;

		ICanUpdate();
		~ICanUpdate();
	};


#endif // __I_CAN_UPDATE_H_
