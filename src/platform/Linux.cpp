#include "../getTime.h"
#include <stdint.h>

#if !defined(_MSC_VER) && !defined(_MSC_EXTENSIONS)
#include <sys/time.h>
#include <unistd.h>

uint64_t getTime()
{
	struct timeval tv;
	gettimeofday(&tv, NULL);

	uint64_t time = tv.tv_usec;
	time /= 1000;
	time += (tv.tv_sec * 1000);

	return time;
}

#endif