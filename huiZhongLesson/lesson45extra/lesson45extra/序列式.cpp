#include <iostream>
#include <map>
#include <sstream>
#include <string>
using namespace std;

int main(){
	//int a[10] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };
	//for (auto m:a)
	//{
	//	char s[8] = {};
	//	sprintf_s(s, "%d", m);
	//	cout << s << endl;
	//}

	//string str = "hello";
	//for (auto m:str)
	//{
	//	char s[8] = {};
	//	sprintf_s(s, "%c", m);
	//	cout << s << endl;
	//}

	map<string, int> ms;
	ms.insert(make_pair("a",1));
	ms.insert(make_pair("b", 2));
	ms.insert(make_pair("c", 3));
	ms.insert(make_pair("d", 4));
	//map<string, int>::iterator its = ms.begin();
	for (auto it : ms)
	{
		char s[16] = {};
		sprintf_s(s, "%s:%d", it.first.c_str(), it.second);
		cout << s << endl;
	}
	return 0;

}