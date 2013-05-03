#include "../getTime.h"
#include <cstdint>

#if defined(_MSC_VER) || defined(_MSC_EXTENSIONS)
#include <windows.h>
#include <time.h>

uint64_t getTime()
{
	FILETIME ft;
	uint64_t time = 0;
	static int tzflag;

	// system time을 구하기
	GetSystemTimeAsFileTime(&ft);

	// unsigned 64 bit로 만들기
	time |= ft.dwHighDateTime;
	time <<= 32;
	time |= ft.dwLowDateTime;

	// 100nano를 1micro로 변환하기
	time /= 10;

	// epoch time으로 변환하기
	time -= 11644473600000000Ui64;    

	return time / 1000;
}

#endif