#include<stdio.h>
#include<stdlib.h>
#include<time.h>
void wait(int seconds)
{
	clock_t endwait;
	endwait = clock() + seconds * CLOCKS_PER_SEC;
	while (clock() < endwait) {}
}
int main()
{
	time_t rt;
	struct tm t;
	long int i;
	for (i = 0; i<3600; i++)
	{
		time(&rt);
		localtime_s(&t,&rt);
		system("cls"); printf("\n\n\n\n\n\n\n\n\t");
		printf("Year: %d ", t.tm_year + 1900);
		printf("Month: %d ", t.tm_mon + 1);
		printf("day: %d ", t.tm_mday);
		printf("hour: %d ", t.tm_hour);
		printf("minute: %d ", t.tm_min);
		printf("second: %d\n", t.tm_sec);
		wait(1);
	}
	return 0;
}