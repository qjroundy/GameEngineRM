#pragma once

#ifndef	 __VAO_H_
#define	 __VAO_H_

#include "utility/common.hpp"

enum class VAO_TYPE
{
	BUFFER,
	COLOUR_INDEX,
	UV_INDEX,
	TEXTURE_COORDINATE,
	NORMALS,
	VERTICES,
};

class VAO
{
public:
	VAO();
	~VAO();
};

#endif /*__VAO_H_ */
