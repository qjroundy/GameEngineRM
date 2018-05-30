#pragma once
#ifndef __MODEL_MESH_H_
#define __MODEL_MESH_H_
#include "utility/common.hpp"
#include "IMesh.h"

namespace GameEngineM
{
	namespace ModelM
	{

		class ModelMesh : public MeshM::IMesh
		{
		public:
			ModelMesh();
			~ModelMesh();
		};

	}
}
#endif /* __MODEL_MESH_H_ */