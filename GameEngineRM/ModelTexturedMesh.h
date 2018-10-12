#pragma once
#ifndef	  __MODEL_TEXTURED_MESH_H
#define	  __MODEL_TEXTURED_MESH_H
#include "ModelMesh.h"
#include "ModelTexture.h"
#include "IModel.h"


	class ModelTexturedMesh : public ModelMesh, public ModelTexture, public IModel
	{
	public:
		ModelTexturedMesh();
		~ModelTexturedMesh();
	};

#endif /* __MODEL_TEXTURED_MESH_H */
