#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
using namespace std;

void rfile(){
	int stage;
	ifstream ifs("./maps/testMap.txt");
	ifs >> stage;
	string st;
	ifs >> st;
	cout << st << endl;
	ifs.close();
}

void xxxx(){
	int stage = 1;
	string s[13] = {};
	s[0] = "00002222220000";
	ofstream outfile("./maps/testMap.txt");
	outfile << stage << endl;
	outfile << s[0] << endl;
	outfile.close();

	rfile();
	system("pause");
}

