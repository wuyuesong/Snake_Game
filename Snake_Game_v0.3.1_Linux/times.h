#include <time.h>

int sleepms (int ms)
{
	clock_t t=clock();
	
	while ((clock()-t)<=CLOCKS_PER_SEC*ms/1000) ;
	
	return 0;
}
