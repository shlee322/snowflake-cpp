#pragma once
#include <cstdint>
class Snowflake
{
public:
	Snowflake(void);
	~Snowflake(void);

	void setEpoch(uint64_t epoch);
	void setMachine(int machine);
	int64_t generate();

private:
	uint64_t epoch;

	uint64_t time;
	int machine;
	int sequence;
};

