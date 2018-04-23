#include <stdio.h>

typedef double(*PCALC)(double, double);

double plus(double a, double b){
	return a + b;
}
double subtrac(double a, double b){
	return a - b;
}

double multi(double a, double b){
	return a * b;
}

double divi(double a, double b){
	return a / b;
}

double myCalc(double a,double b,double(*PCALC)(double,double)){
	return PCALC(a, b);
}

void main(){
	PCALC cal = divi;
	printf("%5.2f", myCalc(10, 20, plus));
}