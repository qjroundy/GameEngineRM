#include "ShaderProgram.h"
#include <filesystem>

using namespace GameEngineM;


ShaderProgram::ShaderProgram(IShaderScript * vertexShader, IShaderScript * fragmentShader)
	: _programId(glCreateProgram())
{
	_shaders.insert_or_assign(GL_VERTEX_SHADER, vertexShader);
	_shaders.insert_or_assign(GL_FRAGMENT_SHADER, fragmentShader);
}

ShaderProgram::ShaderProgram(map<GLenum, IShaderScript*> shaders)
	:  _programId(glCreateProgram()), _shaders(shaders)
{

}

ShaderProgram::ShaderProgram()
	:_programId(glCreateProgram())
{
	
}

ShaderProgram::~ShaderProgram()
{
	glDeleteProgram(_programId);
}

void ShaderProgram::addAttribute(GLuint idx, string attribName)
{
	_attributes[idx] = attribName;
}

void ShaderProgram::addAttribute(string attribName)
{
	static GLuint attribCount = 0;
	_attributes[attribCount++] = attribName;
}

void ShaderProgram::getAllUniformLocations()
{
	for (auto u : _uniforms_locations)
	{
		u.second = getUniformLocation(u.first);
	}
}

void ShaderProgram::bindAttributes()
{
	for (auto a : _attributes)
	{
		bindAttribute(a.first, a.second);
	}
}

void ShaderProgram::addUniform(string name)
{
	_uniforms_locations.insert_or_assign(name, 0);
}

void ShaderProgram::addUniformName(string name)
{
	_uniforms_locations.insert_or_assign(name, 0);
//	_uniforms_locations[name] = 0;
}


//[[depricated("Using attachShader(IShaderScript*) instead.")]]
//ShaderProgram::ShaderProgram(map<GLenum, IShaderScript*> shaders)
//{
//	_programId = glCreateProgram();
//	_shaders.insert(shaders.begin(), shaders.end());
//	//std::copy(shaders.begin(), shaders.end(), _shaders.begin())
//}

void ShaderProgram::generateShaderProgram()
{
	for (auto s : _shaders)
	{
		
		glAttachShader(_programId, s.second->getShaderId());
	}
}

void ShaderProgram::bindAttribute(GLuint attribute, string variableName)
{
	glBindAttribLocation(_programId, attribute, variableName.c_str());
}

void ShaderProgram::load()
{
	debugInfo("Loading Shader");
	generateShaderProgram();
	bindAttributes();
	buildProgram();
	getAllUniformLocations();
	debugInfo("Shader Loaded");

}
void ShaderProgram::buildProgram()
{
	GLint formats = 0;
	GLint binaryLength = 0;
	
	glGetIntegerv(GL_NUM_PROGRAM_BINARY_FORMATS, &formats);
	GLint * binaryFormats = new GLint[formats];
	
	glGetIntegerv(GL_PROGRAM_BINARY_FORMATS, binaryFormats);
	u8 * binary;

	if (filesystem::exists(("SHADER_" + _hashName + ".bin").c_str()))
	{
		debugInfo("Cache file exists");
		FILE* fp = fopen(("SHADER_" + _hashName + ".bin").c_str(), "rb");
		fread(binaryFormats, sizeof(GLuint), formats, fp);
		fread(&binaryLength, sizeof(GLuint), 1, fp);
		binary = new u8[binaryLength];
		fread(binary, binaryLength, 1, fp);
		fclose(fp);
		glProgramBinary(_programId, *binaryFormats, binary, binaryLength);
	}
	else
	{
		glProgramParameteri(_programId, GL_PROGRAM_BINARY_RETRIEVABLE_HINT, GL_TRUE);
		glLinkProgram(_programId);
		glValidateProgram(_programId);
		glGetProgramiv(_programId, GL_PROGRAM_BINARY_LENGTH, &binaryLength);
		binary = new u8[binaryLength];
		if (binaryLength > 0)
		{
			glGetProgramBinary(_programId, binaryLength, NULL, (GLenum*)binaryFormats, binary);
			FILE* fp = fopen(("SHADER_" + _hashName + ".bin").c_str(), "wb");
			fwrite(binaryFormats, sizeof(GLuint), formats, fp);
			fwrite(&binaryLength, sizeof(GLuint), 1, fp);
			fwrite(binary, binaryLength, 1, fp);
			fclose(fp);
			debugInfo("Shader cached successfully");
		}
		else
		{
			debugLog("Shader failed to cache");
		}
	}
	delete binary;

}


[[deprecated("Use attachShader(IShaderScript* script) instead")]]
void ShaderProgram::attachVertexShader(IShaderScript * vertexShader)
{
	_shaders[GL_VERTEX_SHADER] = vertexShader;
}

[[deprecated("Use attachShader(IShaderScript* script) instead")]]
void ShaderProgram::attachFragmentShader(IShaderScript * fragmentShader)
{
	_shaders[GL_FRAGMENT_SHADER] = fragmentShader;

}

[[deprecated("Use attachShader(IShaderScript* script) instead")]]
void ShaderProgram::attachGeometryShader(IShaderScript * geometryShader)
{
	_shaders[GL_GEOMETRY_SHADER] = geometryShader;
}

template<GLenum T>
const IShaderScript& ShaderProgram::getShaderScript()
{
	return *_shaders.at(T);
}


const IShaderScript& ShaderProgram::getShaderScript(GLenum type)
{
	return *_shaders.at(type);
}

const IShaderScript& ShaderProgram::operator[](GLenum type)
{
	return *_shaders[type];
}

void ShaderProgram::start()
{
	glUseProgram(_programId);
}


void ShaderProgram::stop()
{
	glUseProgram(0);
}

void ShaderProgram::cleanUp()
{

	for (auto s : _shaders)
	{
		glDetachShader(_programId, s.second->getShaderId());
		s.second->cleanUp();
	}

	glDeleteProgram(_programId);

}

//template<GLenum T>
//void ShaderProgram::attachShader(IShaderScript *shader)
//{
//	_shaders[T] = shader;
//}

void ShaderProgram::attachShader(IShaderScript *shader, GLenum shaderType)
{
	_shaders[shaderType] = shader;
}

GLuint ShaderProgram::getUniformLocation(string uniformName)
{
	return glGetUniformLocation(_programId, uniformName.c_str());
}

void load()
{

}

void start()
{

}

void stop()
{

}

void cleanUp()
{

}

//void ShaderProgram::addUniform(string name)
//{
//	addUniformName(name);
//}