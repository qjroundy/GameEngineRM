#pragma once
#ifndef __SHADER_PROGRAM_H
#define __SHADER_PROGRAM_H
#include "utility/common.hpp"
#include "IShaderProgram.h"
#include "ShaderScript.h"
#include <map>

class ShaderProgram : public IShaderProgram
{
private:
	map<GLenum, IShaderScript*> _shaders;
	map<GLuint, string> _attributes;
	map<string, GLint> _uniforms_locations;
	GLuint _programId;
	string _name;
	string _hashName;
public:
	void addUniform(string name) override;
	void addUniformName(string name) override;
	ShaderProgram();
	ShaderProgram(IShaderScript * vertexShader, IShaderScript * fragmentShader);
	ShaderProgram(map<GLenum, IShaderScript*> shaders);
	inline void loadUniform(string name, GLfloat value)			override { loadUniform(_uniforms_locations[name], value); };
	inline void loadUniform(string name, GLint value)			override { loadUniform(_uniforms_locations[name], value); };
	inline void loadUniform(string name, GLboolean value)		override { loadUniform(_uniforms_locations[name], value); };
	inline void loadUniform(string name, vec3 value)			override { loadUniform(_uniforms_locations[name], value); };
	inline void loadUniform(string name, vec4 value)			override { loadUniform(_uniforms_locations[name], value); };
	inline void loadUniform(string name, mat4 value)			override { loadUniform(_uniforms_locations[name], value); };
	inline void loadUniform(GLuint location, GLfloat value)		override { loadFloat(location, value); };
	inline void loadUniform(GLuint location, GLint value)		override { loadInt(location, value); };
	inline void loadUniform(GLuint location, GLboolean value)	override { loadInt(location, value); };
	inline void loadUniform(GLuint location, vec3 value)		override { loadVector3f(location, value); };
	inline void loadUniform(GLuint location, vec4 value)		override { loadVector4f(location, value); };
	inline void loadUniform(GLuint location, mat4 value)		override { loadMatrix4f(location, value); };
	~ShaderProgram();
	void addAttribute(GLuint idx, string attribName) override;
	void addAttribute(string attribName) override;
	void getAllUniformLocations() override;
	void bindAttributes() override;
	void bindAttribute(GLuint attribute, string variableName) override;
	void generateShaderProgram() override;
	void load() override;

	[[deprecated]]
	void attachVertexShader(IShaderScript * vertexShader);
	[[deprecated]]
	void attachFragmentShader(IShaderScript * fragmentShader);
	[[deprecated]]
	void attachGeometryShader(IShaderScript* geometryShader);
	virtual void start() override;
	virtual void stop() override;
	virtual void cleanUp() override;
	const IShaderScript & operator[](GLenum type) override;
	const GLuint programId() override { return _programId; }
	//template<GLenum T>  const IShaderScript& getShaderScript();
	//template<GLenum T>  void attachShader(IShaderScript *);
	template<GLenum T> const IShaderScript& getShaderScript();
	void buildProgram() override;
	const IShaderScript& getShaderScript(GLenum type) override;
	void attachShader(IShaderScript *shader, GLenum shaderType) override;
	GLuint getUniformLocation(string uniformName) override;

	virtual void setName(string name) {
		_name = name;
		_hashName = getHashName();
	}

	virtual string& getName() {
		return _name;
	}

	inline virtual const string& getHashName()
	{
		unique_ptr<hash<string>>hasher{};
		if (_hashName.empty())
		{
			return _hashName = to_string((*hasher)(getName()));
		}

		return _hashName;
	}
};

#endif __SHADER_PROGRAM_H