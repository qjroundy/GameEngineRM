#pragma once
#ifndef __MODEL_H_
#define __MODEL_H_

#include "utility/common.hpp"
#include <string>
#include "ModelTexture.h"
#include "ModelMesh.h
"
namespace GameEngineM
{
	namespace ModelM
	{

		class Model
		{
		private:

		protected:
			string _name = "";
			ModelTexture _texture{};
			ModelMesh _mesh{};

		public:
			Model(string _name = "", ModelTexture texture, ModelMesh mesh);
			Model();

			void attachTexture(ModelTexture texture);
			void attachMesh(ModelMesh mesh);
			void attachName(string name);

			ModelTexture& getTexture() { return _texture; }
			ModelMesh& getMesh() { return _mesh; }
			string& getName();

			~Model();
		};

	}
}
#endif /* __MODEL_H_ */