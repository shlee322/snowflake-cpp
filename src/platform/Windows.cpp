#include "../getTime.h"
#include <stdint.h>

#if defined(_MSC_VER) || defined(_MSC_EXTENSIONS)
#include <windows.h>
#include <time.h>

uint64_t getTime()
{
	FILETIME ft;
	uint64_t time = 0;
	static int tzflag;

	GetSystemTimeAsFileTime(&ft);

	time |= ft.dwHighDateTime;
	time <<= 32;
	time |= ft.dwLowDateTime;

	time /= 10;

	time -= 11644473600000000Ui64;    

	return time / 1000;
}

#endif