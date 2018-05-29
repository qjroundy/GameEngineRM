#pragma once
//
#ifndef _COMMON_H
#define _COMMON_H
// This header is used by most or all GameEngine components.

#include <gl/glew.h>
#include <GL/GL.h>
#include <GL/wglew.h>

#include <GLFW/glfw3.h>
#include <soil.h>

#include <glm/ext.hpp>
using namespace glm;

#include <AL/alc.h>
#include <AL/al.h>
#include <AL/efx.h>
#include <AL/alut.h>

#include <iostream>
#include <string>
#include <fstream>

using namespace std;

#define NEWLINE					 "\n"
#define WIDE_NEWLINE			L"\n"
#define CARRIAGE_RETURN			 "\r"
#define WIDE_CARRIAGE_RETURN	L"\r"

inline wostream& nl(wostream& o) { return o << WIDE_NEWLINE; }
inline ostream& nl(ostream& o) { return o << NEWLINE; }

#define UM	UtiltyM
#define GM	GameM
#define DM	DisplayM
#define EM	EntityM
#define TM	TerrainM
#define MM	ModelM
#define RM	RenderM
#define SM	ShaderM

#define ECONSOLE(MSG)		wcerr << L##MSG << endl;
#define CONSOLE(MSG)		wcout << L##MSG << nl
#define LOG(MSG)
#ifndef DEBUG
	#define debugMessage(MSG)
	#define debugConsole(MSG)	
	#define debugMessage(MSG)	
	#define debugInfo(MSG)		
	#define debugLog(MSG)
#else
	#define debugConsole(MSG)		CONSOLE(MSG)
	#define debugMessage(MSG)		LOG(MSG); wcout << L##MSG << nl
	#define debugInfo(MSG)			LOG(MSG)
	#define debugLog(MSG)			LOG(MSG)
	#define debugError(MSG,ERR)		ECONSOLE(MSG);exit(ERR)
#endif

#endif /* COMMON_HPP */