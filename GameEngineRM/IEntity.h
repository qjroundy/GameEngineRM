#pragma once
#ifndef	  __I_ENTITY_H
#define	  __I_ENTITY_H

#include "utility/common.hpp"

namespace GameEngineM
{
	class IEntity
	{
	protected:
		vec3 _position{ 0,0,0 };
		vec3 _rotation{ 0,0,0 };
		GLint _scale = 0;

	public:
		IEntity();
		~IEntity();
	};
}
#endif /* __I_ENTITY_H */

