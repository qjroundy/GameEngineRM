#pragma once

#ifndef __MATH_H
#define __MATH_H

#include "utility/common.hpp"

mat4 createTransformationMatrix(
	vec3 translation,
	GLfloat rx,
	GLfloat ry,
	GLfloat rz,
	GLfloat scale
);

GLfloat barryCentric(vec3 p1, vec3 p2, vec3 p3, vec2 pos);

//mat4* createViewMatrix(Camera camera);

class Math
{
public:
	Math();
	~Math();
};

#endif __MATH_H