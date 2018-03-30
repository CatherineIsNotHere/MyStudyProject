#include "stdio.h"

void main(){
	int day = 0;
	while (true){
		printf("ÇëÊäÈëÊı×Ö1~7£º");
		scanf_s("%d", &day);
		if (day > 7 || day < 1){
			printf("ÊäÈë´íÎó,ÇëÖØÊä\n");
		}
		else{
			break;
		}
	}
	//if (day == 1)
	//	printf("today is Monday");
	//if (day == 2)
	//	printf("today is Tuesday");
	//if (day == 3)
	//	printf("today is Wednesday");
	//if (day == 4)
	//	printf("today is Thursday");
	//if (day == 5)
	//	printf("today is Friday");
	//if (day == 6)
	//	printf("today is Saturday");
	//if (day == 7)
	//	printf("today is Sunday");
	//caseºó±ØĞëÎªÕûÊı
	switch (day)
	{
	case 1:
		printf("today is Monday\n");
		break;
	case 2:
		printf("today is Tuesday\n");
		break;
	case 3:
		printf("today is Wednesday\n");
		break;
	case 4:
		printf("today is Thursday\n");
		break;
	case 5:
		printf("today is Friday\n");
		break;
	case 6:
		printf("today is Saturday\n");
		break;
	case 7:
		printf("today is Sunday\n");
		break;
	default:
		printf("ÊäÈë´íÎó\n");
		break;
	}
}