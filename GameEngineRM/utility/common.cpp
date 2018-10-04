#include "common.hpp"

OS checkOS()
{
#ifdef WIN32
	return OS::WINDOWS;
#elif defined WIN66
	return OS::WINDOWS;
#endif
}
