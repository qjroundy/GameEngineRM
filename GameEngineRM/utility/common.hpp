#pragma once
#ifndef _COMMON_H
#define _COMMON_H
#define _CRT_SECURE_NO_WARNINGS

#include <gl/glew.h>
#include <GL/GL.h>
#include <GL/wglew.h>
#include <GLFW/glfw3.h>
#include <soil.h>
#include <GL/freeglut.h>
#include <glm/ext.hpp>
using namespace glm;

#include <AL/alc.h>
#include <AL/al.h>
#include <AL/efx.h>
#include <AL/alut.h>

#include <iostream>
#include <string>
#include <fstream>
#include <chrono>
#include <ctime>

using namespace std;

#ifndef __LOGFILE_PATH_
#define __LOGFILE_PATH_ "error.log"
static wofstream __LOGFILE__;
#endif

#define NEWLINE					 "\n"
#define WIDE_NEWLINE			L"\n"
#define CARRIAGE_RETURN			 "\r"
#define WIDE_CARRIAGE_RETURN	L"\r"

inline wostream& nl(wostream& o) { return o << WIDE_NEWLINE; }
inline ostream& nl(ostream& o) { return o << NEWLINE; }
//inline fstream& nl(fstream& o) { return o << std::endl; }

#define UM	UtiltyM
#define GM	GameM
#define DM	DisplayM
#define EM	EntityM
#define TM	TerrainM
#define MM	ModelM
#define RM	RenderM
#define SM	ShaderM
using std::chrono::system_clock;


#ifndef _NO_LOG_TIMESTAMP_
#define TIMESTAMP TimeStamp << " : "
inline wostream& TimeStamp(wostream& o)
{
	time_t t = system_clock::to_time_t(system_clock::now());
	return o << strtok(ctime(&t),"\n");
}
#else
#define TIMESTAMP ""
#endif

#define FILE_OUT(MSG)		__LOGFILE__.open(__LOGFILE_PATH_, ios::app);__LOGFILE__ << TimeStamp << " : " << L##MSG << nl;__LOGFILE__.close()
#define ECONSOLE(MSG)		wcerr << TIMESTAMP << L##MSG << endl
#define CONSOLE(MSG)		wcout << TIMESTAMP << L##MSG << nl
#define EXIT_ERROR(ERR)		cin.get();exit(ERR)
#define FELOG(MSG)			FILE_OUT("ERROR: "##MSG)
#define FLOG(MSG)			FILE_OUT(MSG)
#define LOG(MSG)			wcout << TimeStamp << " : " << L##MSG << nl
#define FILOG(MSG)			FILE_OUT("INFO: "##MSG)
#ifndef DEBUG
	#define debugMessage(MSG)
	#define debugConsole(MSG)	
	#define debugMessage(MSG)	
	#define debugInfo(MSG)		
	#define debugLog(MSG)
#else
	#define debugConsole(MSG)		CONSOLE(MSG)
	#define debugMessage(MSG)		CONSOLE(MSG)
	#define debugInfo(MSG)			CONSOLE(MSG);FILOG(MSG)
	#define debugLog(MSG)			CONSOLE(MSG);FLOG(MSG)
	#define debugError(MSG,ERR)		ECONSOLE(MSG);FELOG(MSG);EXIT_ERROR(ERR)
#endif

#endif /* COMMON_HPP */