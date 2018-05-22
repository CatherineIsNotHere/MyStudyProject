#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <string>
using namespace std;

class CPerson{
public:
	int age=0;
	float height=0;
	float weight=0;
	static char* born;
	static void cry(){
		cout << "I am crying!" << endl;
	}
	static void eat(){
		cout << "I am eating!" << endl;
	}
	static void sleep(){
		cout << "I am sleeping!" << endl;
	}
	void work(){
		cout << "I am working" << endl;
	}

};
char* CPerson::born = { "Îäºº" };
void main(){
	cout << CPerson::born << endl;
	CPerson::cry();
	CPerson::eat();
	CPerson::sleep();
}