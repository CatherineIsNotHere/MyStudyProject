#include "stdio.h"

/*
	鸡翁一值钱五，鸡母一值钱三，鸡雏三值钱一。百钱买百鸡，问鸡翁、鸡母、鸡雏各几何
*/
void main(){
	int cock, hen, chicken;
	for (cock = 0; cock <= 20;cock++)
	for (hen = 0; hen <= 33;hen++)
	for (chicken = 0; chicken < 99;chicken+=3)
	if (5*cock+3*hen+chicken/3==100)
	if (cock + hen + chicken == 100)
		printf("公鸡数量%d,母鸡数量%d,小鸡数量%d\n",cock,hen,chicken);
}