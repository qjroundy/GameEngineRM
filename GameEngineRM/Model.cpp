#include "Model.h"

namespace GameEngineM
{
	namespace ModelM
	{


		Model::Model(string name, ModelTexture texture, ModelMesh mesh)
			: _name(name), _texture(texture), _mesh(mesh)
		{
		}


		Model::~Model()
		{
		}

	}
}