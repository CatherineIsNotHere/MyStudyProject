#include <stdio.h>
#include <stdlib.h>

char* getWeekDay(int a){
	static char* c = {};
	switch (a)
	{
	case 1:
		c = "Monday";
		break;
	case 2:
		c = "Tuesday";
		break;
	case 3:
		c = "Wednesday";
		break;
	case 4:
		c = "Thursday";
		break;
	case 5:
		c = "Friday";
		break;
	case 6:
		c = "Saturday";
		break;
	case 7:
		c = "Sunday";
		break;
	default:
		break;
	}
	return c;
}


void main(){
	char* p = getWeekDay(1);
	system("pause");
}