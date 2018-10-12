#pragma once
#ifndef __ENTITY_RENDERER_H
#define __ENTITY_RENDERER_H
#include "utility/common.hpp"
#include "Renderer.h"
#include "IEntity.h"
#include <vector>

class EntityRenderer : public Renderer
{
	vector<IEntity*> _entities;

public:

	void addEntities(IEntity* entity);
	void addEntities(vector<IEntity*> entities);

	EntityRenderer();
	~EntityRenderer();
};

#endif /* __ENTITY_RENDERER_H */