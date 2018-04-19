#include "stdio.h"
//阳阳每天都会买苹果，每颗8毛，每天会买前一天2倍的苹果，每天买苹果不会超过100颗，问阳阳买了几天，平均花了多少钱
void main(){
	int n = 2, day = 0, num = 0;
	float money = 0, averange = 0;
	while (n < 100){
		money = 0.8*n;
		day++;
		num += n;
		n = n * 2;
	}
	averange = money / day;
	printf("阳阳总共买了%d颗苹果，买了%d天,平均花了%2.3f块钱", num, day, averange);
}
