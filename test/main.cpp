#include <stdio.h>
#include "../src/Snowflake.h"

int main()
{
	Snowflake* snow = new Snowflake();
	snow->setEpoch(1367505795100);
	snow->setMachine(30);

	while(true) {
		printf(" %lld\n", snow->generate()); 
	}
	return 0;
}