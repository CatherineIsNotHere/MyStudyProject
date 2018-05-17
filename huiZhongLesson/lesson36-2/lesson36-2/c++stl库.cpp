#include <iostream>
#include <fstream>
#include <sstream>
#include <algorithm>
#include <map>
using namespace std;

void show(const map<int, string>::value_type &pair){
	cout << pair.first << "," << pair.second << endl;
}

void main(){
	//int n = 99;
	//float f = 9.1f;
	//double d = 100.123;
	//char c = 'c';
	//bool b = true;
	//char p[512] = "∫∫◊÷≤‚ ‘ABC123";
	//ofstream outfile("./test.txt");
	//outfile << n << endl;
	//outfile << f << endl;
	//outfile << d << endl;
	//outfile << c << endl;
	//outfile << b << endl;
	//outfile << p << endl;
	//outfile.close();
	//system("pause");

	//ifstream ifs("./test.txt");
	//ifs >> n;
	//ifs >> f;
	//ifs >> d;
	//ifs >> c;
	//ifs >> b;
	//ifs >> p;
	//ifs.close();
	//system("pause");

	//stringstream stream;
	//int i = 1000;
	//stream << i;
	//string s;
	//stream >> s;
	//char r2[8];
	//stream.clear();
	//stream << 8888;
	//stream >> r2;

	//string s3;
	//int n3;
	//stream.clear();
	//stream << "ccc 333 ddd 666";
	//while (stream>>s3>>n3){
	//	cout << s3 << "," << n3 << endl;
	//}



	stringstream ss;
	ss << "◊÷∑˚¥Æ1" << endl;
	ss << "◊÷∑˚¥Æ2" << endl;
	ss << "◊÷∑˚¥Æ3" << endl;
	ss << "◊÷∑˚¥Æ4" << endl;
	ss << "◊÷∑˚¥Æ5" << endl;
	char buf[512];
	while (ss.getline(buf,sizeof(buf)))
	{
		printf("%s\n",buf);
	}
	system("pause");

	map<int, string> m;
	m.insert(make_pair(10,"china"));
	m[100] = "usa";
	m[200] = "hk";
	m[300] = "en";
	for_each(m.begin(),m.end(),show);//foreachÀ„∑®
	system("pause");
}