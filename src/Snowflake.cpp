#include "Snowflake.h"
#include "getTime.h"

Snowflake::Snowflake(void)
{
	this->epoch = 0;
	this->time = 0;
	this->machine = 0;
	this->sequence = 0;
}

Snowflake::~Snowflake(void)
{
}

void Snowflake::setEpoch(uint64_t epoch)
{
	this->epoch = epoch;
}

void Snowflake::setMachine(int machine)
{
	this->machine = machine;
}

int64_t Snowflake::generate()
{
	int64_t value = 0;
	uint64_t time = getTime() - this->epoch;

	//시간 41bit
	value |= time << 22;

	//머신 10bit
	value |= this->machine & 0x3FF << 12;

	//시간이 변하면 증가값 초기화
	if(time!=this->time) {
		this->time = time;
		this->sequence = 0;
	}

	//증가값 12bit
	value |= this->sequence++ & 0xFFF;

	return value;
}
