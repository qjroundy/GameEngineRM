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
static ofstream __LOGFILE__;
#endif

#define NEWLINE					 "\n"
#define CARRIAGE_RETURN			 "\r"

inline ostream& nl(ostream& o) { return o << NEWLINE; }

using std::chrono::system_clock;

#ifndef _NO_LOG_TIMESTAMP_
#define TIMESTAMP TimeStamp << " : "
inline ostream& TimeStamp(ostream& o)
{
	time_t t = system_clock::to_time_t(system_clock::now());
	return o << strtok(ctime(&t), "\n");
}
#else
#define TIMESTAMP ""
#endif
#define FILE_OUT(STR)		__LOGFILE__.open(__LOGFILE_PATH_, ios::app);__LOGFILE__ << TimeStamp << " : " << STR << nl;__LOGFILE__.close()
#define ECONSOLE(STR)		cerr << TIMESTAMP << STR << endl
#define CONSOLE(STR)		cout << TIMESTAMP << STR << nl
#define EXIT_ERROR(ERR)		cin.get();exit(ERR)
#define FELOG(STR)			FILE_OUT("ERROR: " << STR)
#define FLOG(STR)			FILE_OUT(STR)
#define LOG(STR)			cout << TimeStamp << " : " << STR << nl
#define FILOG(STR)			FILE_OUT("INFO: " << STR)
#ifndef DEBUG
#define debugMessage(MSG)
#define debugConsole(MSG)	
#define debugMessage(MSG)	
#define debugInfo(MSG)	
#define debugError(MSG,ERR)
#define debugLog(MSG)
#else
#define debugConsole(STR)		CONSOLE(STR)
#define debugMessage(STR)		CONSOLE(STR)
#define debugInfo(STR)			CONSOLE(STR);FILOG(STR)
#define debugLog(STR)			CONSOLE(STR);FLOG(STR)
#define debugError(STR,ERR)		ECONSOLE(STR);FELOG(STR);EXIT_ERROR(ERR)
#endif

//
//template <typedef ...T>

#endif /* COMMON_HPP */

