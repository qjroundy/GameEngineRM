#pragma once
#ifndef	  __I_ENTITY_H
#define	  __I_ENTITY_H

#include "utility/common.hpp"

namespace GameEngineM
{
	namespace EntityM
	{

		class IEntity
		{
		protected:
			vec3 _position{ 0,0,0 };

		public:
			IEntity();
			~IEntity();
		};

	}
}
#endif /* __I_ENTITY_H */

