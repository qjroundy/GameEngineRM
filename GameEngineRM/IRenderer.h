#pragma once
#ifndef ___I_RENDERER_H_
#define ___I_RENDERER_H_
#include "IShaderProgram.h"

namespace GameEngineM
{
	using namespace ShaderM;

	class IRenderer
	{
	private:

	protected:
		IShaderProgram _shaderProgram;
	public:

		IRenderer();
		IRenderer(IShaderProgram shaderProgram);
		~IRenderer();

		IShaderProgram& getShaderProgram() { return _shaderProgram; }
		void removeShaderProgram();
		//void attachShaderProgram(IShaderProgram shaderProgram);
		//void addEntity(IEntity entity);
		//void addEntitities(vector<IEntity> entities); // add pre-created data
		//void addEntitities(map<IModelMesh, IModelTexture> entities); // straigth add from raw data?
	};
}

#endif