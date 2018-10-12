#pragma once
#ifndef __I_SHADER_PROGRAM_H_
#define __I_SHADER_PROGRAM_H_

#include "ShaderScript.h"
#include <map>

class IShaderProgram
{
private:
public:
	virtual void bindAttributes() = 0;
	virtual void getAllUniformLocations() = 0;
	virtual void addAttribute(string attribName) = 0;
	virtual void addAttribute(GLuint idx, string attribName) = 0;
	virtual GLuint getUniformLocation(string uniformName) = 0;
	virtual void generateShaderProgram() = 0;
	virtual inline const  GLuint programId() = 0;

	virtual void load() = 0;
	virtual void addUniform(string name) = 0;
	virtual void addUniformName(string name) = 0;

	virtual void loadUniform(GLuint location, GLboolean value) = 0;
	virtual void loadUniform(string name, GLfloat value) = 0;
	virtual void loadUniform(string name, GLint value) = 0;
	virtual void loadUniform(string name, GLboolean value) = 0;
	virtual void loadUniform(string name, vec3 value) = 0;
	virtual void loadUniform(string name, vec4 value) = 0;
	virtual void loadUniform(string name, mat4 value) = 0;
	virtual void loadUniform(GLuint location, GLfloat value) = 0;
	virtual void loadUniform(GLuint location, GLint value) = 0;
	virtual void loadUniform(GLuint location, vec3 value) = 0;
	virtual void loadUniform(GLuint location, vec4 value) = 0;
	virtual void loadUniform(GLuint location, mat4 value) = 0;

	virtual void buildProgram() = 0;
	IShaderProgram() = default;
	//IShaderProgram(IShaderScript * vertexShader, IShaderScript * fragmentShader);
	~IShaderProgram();

	virtual const IShaderScript& operator[](GLenum type) = 0;

	//template<GLenum T>  const IShaderScript& getShaderScript();
	//template<GLenum T>  void attachShader(IShaderScript *);

	virtual void attachShader(IShaderScript *, GLenum) = 0;
	virtual const IShaderScript& getShaderScript(GLenum type) = 0;

	virtual void attachVertexShader(IShaderScript * vertexShader) = 0;
	virtual void attachFragmentShader(IShaderScript * fragmentShader) = 0;

	virtual void start() = 0;
	virtual void stop() = 0;
	virtual void cleanUp() = 0;
	virtual void bindAttribute(GLuint attr, string name) = 0;

	template<typename T> void updateUniform(GLuint location, T value) { loadUniform(location, value); };
	template<typename T> void updateUniform(string name, T value) { loadUniform(name, value); };


	void loadFloat(GLuint location, GLfloat value);
	void loadInt(GLuint location, GLint value);
	void loadBool(GLuint location, GLboolean value);
	void loadVector3f(GLuint location, vec3 value);
	void loadVector4f(GLuint location, vec4 value);
	void loadMatrix4f(GLuint location, mat4 value);
};

#endif /* __I_SHADER_PROGRAM_H_ */