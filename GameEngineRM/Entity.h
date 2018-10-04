#pragma once
#ifndef	  __ENTITY_H_ 
#define	  __ENTITY_H_ 

#include "IEntity.h"

namespace GameEngineM
{

	class Entity
	{
	private:
		vec3 _position{ 0,0,0 };
		vec3 _rotation{ 0,0,0 };
		GLint _scale = 0;

	public:
		Entity();
		~Entity();
	};

}

#endif /* __ENTITY_H_ */